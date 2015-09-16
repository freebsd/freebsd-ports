--- src/gnu/io/RXTXPort.java.orig	2008-11-13 23:37:45.000000000 +0000
+++ src/gnu/io/RXTXPort.java	2015-05-11 16:51:34.000000000 +0100
@@ -56,6 +56,7 @@
 |   All trademarks belong to their respective owners.
 --------------------------------------------------------------------------*/
 package gnu.io;
+
 import java.io.InputStream;
 import java.io.OutputStream;
 import java.io.IOException;
@@ -65,93 +66,133 @@
 /**
 * An extension of gnu.io.SerialPort
 * @see gnu.io.SerialPort
-*/
+**/
 
 final public class RXTXPort extends SerialPort
 {
-	/* I had a report that some JRE's complain when MonitorThread
-	   tries to access private variables
-	*/
+	/** 
+	*	I had a report that some JRE's complain when MonitorThread
+	*	 tries to access private variables
+	**/
 
-	protected final static boolean debug = false;
+	protected final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 	protected final static boolean debug_read = false;
 	protected final static boolean debug_read_results = false;
 	protected final static boolean debug_write = false;
-	protected final static boolean debug_events = false;
+	protected final static boolean debug_events = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );;
 	protected final static boolean debug_verbose = false;
 
 	private static Zystem z;
 
 	static
 	{
-		try {
+		if (debug) System.out.println("RXTXPort:Static()");
+		
+		try 
+		{
 			z = new Zystem();
-		} catch ( Exception e ) {}
+		} 
+		catch (Exception e) 
+		{
+			if (debug) System.out.println("RXTXPort:Static:Exception Thrown");	
+		}
 
-		if(debug ) 
-			z.reportln( "RXTXPort {}");
-		System.loadLibrary( "rxtxSerial" );
+		if(debug) System.out.println(" Loading Library...");
+		
+		System.loadLibrary("rxtxSerial" );
+		
+		if(debug) System.out.println(" Initializing...");
+		
 		Initialize();
+		
+		if(debug) System.out.println("RXTXPort:Static:Exit");
+		
 	}
 
-	/** Initialize the native library */
+	/**
+	*	Initialize the native library
+	**/
+	
 	private native static void Initialize();
+	
 	boolean MonitorThreadAlive=false;
 
 	/** 
-	*  Open the named port
-	*  @param name the name of the device to open
-	*  @throws  PortInUseException
-	*  @see gnu.io.SerialPort
-	*/
-	public RXTXPort( String name ) throws PortInUseException
-	{
-		if (debug)
-			z.reportln( "RXTXPort:RXTXPort("+name+") called");
-	/* 
-	   commapi/javadocs/API_users_guide.html specifies that whenever
-	   an application tries to open a port in use by another application
-	   the PortInUseException will be thrown
-
-	   I know some didnt like it this way but I'm not sure how to avoid
-	   it.  We will just be writing to a bogus fd if we catch the 
-	   exeption
-
-	   Trent
-	*/
-	//	try {
-			fd = open( name );
-			this.name = name;
-
-			MonitorThreadLock = true;
-			monThread = new MonitorThread();
-			monThread.start();
-			waitForTheNativeCodeSilly();
-			MonitorThreadAlive=true;
-	//	} catch ( PortInUseException e ){}
-		timeout = -1;	/* default disabled timeout */
-		if (debug)
-			z.reportln( "RXTXPort:RXTXPort("+name+") returns with fd = " +
-				fd);
+	*	Open the named port
+	*	@param	name the name of the device to open
+	*	@throws	PortInUseException
+	*	@see	gnu.io.SerialPort
+	**/
+	
+	public RXTXPort( String name )
+	throws PortInUseException
+	{
+		if (debug) System.out.println("RXTXPort:RXTXPort(" + name + ")");
+		
+		/**
+		*	commapi/javadocs/API_users_guide.html specifies that whenever
+		*	an application tries to open a port in use by another application
+		*	the PortInUseException will be thrown
+		*	
+		*	I know some didnt like it this way but I'm not sure how to avoid
+		*	it.  We will just be writing to a bogus fd if we catch the 
+		*	exeption
+		*	
+		*	Trent
+		**/
+	
+		/**
+		*	try {
+		**/
+		
+		fd = open( name );
+		this.name = name;
+		
+		MonitorThreadLock = true;
+		monThread = new MonitorThread();
+		monThread.start();
+		waitForTheNativeCodeSilly();
+		MonitorThreadAlive=true;
+		
+		/**
+		*	} catch ( PortInUseException e ){}
+		**/
+		
+		/**
+		*	default disabled timeout
+		**/
+		
+		timeout = -1;	
+		
+		if (debug) System.out.println(
+			"RXTXPort:RXTXPort(" + name + ") returns with fd = " + fd
+		);
 	}
+	
 	private native synchronized int open( String name )
-		throws PortInUseException;
+	throws PortInUseException;
 
 
-	/* dont close the file while accessing the fd */
+	/**
+	*	dont close the file while accessing the fd
+	**/
+	
 	int IOLocked = 0;
+	
 	Object IOLockedMutex = new Object();
 
 	/** File descriptor */
 	private int fd = 0;
 
-	/** a pointer to the event info structure used to share information
-	    between threads so write threads can send output buffer empty
-	    from a pthread if need be.
-
-	    long for 64 bit pointers.
-	*/
+	/**
+	*	a pointer to the event info structure used to share information
+	*	between threads so write threads can send output buffer empty
+	*	from a pthread if need be.
+	*	
+	*	long for 64 bit pointers.
+	**/
 	long eis = 0;
+	
 	/** pid for lock files */
 	int pid = 0;
 
@@ -160,142 +201,202 @@
 
 	/** Output stream */
 	private final SerialOutputStream out = new SerialOutputStream();
+	
 	/** 
-	*  get the OutputStream
-	*  @return OutputStream
-	*/
+	*	get the OutputStream
+	*	@return	OutputStream
+	**/
 	public OutputStream getOutputStream()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getOutputStream() called and returning");
+		{
+			System.out.println(
+				"RXTXPort:getOutputStream()"
+			);
+		}
+		
 		return out;
+		
 	}
 
 	/** Input stream */
 	private final SerialInputStream in = new SerialInputStream();
+	
 	/** 
-	*  get the InputStream
-	*  @return InputStream
-	*  @see java.io.InputStream
-	*/
+	*	get the InputStream
+	*	@return	InputStream
+	*	@see	java.io.InputStream
+	**/
+	
 	public InputStream getInputStream()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getInputStream() called and returning");
+		{
+			System.out.println(
+				"RXTXPort:getInputStream:Exit"
+			);
+		}
 		return in;
 	}
 
-	/** 
-	*  Set the SerialPort parameters
-	*  1.5 stop bits requires 5 databits
-	*  @param  b baudrate
-	*  @param  d databits
-	*  @param  s stopbits
-	*  @param  p parity
-	*  @throws UnsupportedCommOperationException
-	*  @see gnu.io.UnsupportedCommOperationException
-
-	*  If speed is not a predifined speed it is assumed to be
-	*  the actual speed desired.
-	*/
 	private native int nativeGetParity( int fd );
 	private native int nativeGetFlowControlMode( int fd );
-	public synchronized void setSerialPortParams( int b, int d, int s,
-		int p )
-		throws UnsupportedCommOperationException
-	{
-		if (debug)
-			z.reportln( "RXTXPort:setSerialPortParams(" +
-				b + " " + d + " " + s + " " + p + ") called");
+	
+	/** 
+	*	Set the SerialPort parameters
+	*	1.5 stop bits requires 5 databits
+	*	@param  b baudrate
+	*	@param  d databits
+	*	@param  s stopbits
+	*	@param  p parity
+	*	@throws UnsupportedCommOperationException
+	*	@see gnu.io.UnsupportedCommOperationException
+	*	
+	*	If speed is not a predifined speed it is assumed to be
+	*	the actual speed desired.
+	**/
+	
+	public synchronized void setSerialPortParams(
+		int b, 
+		int d,
+		int s,
+		int p
+	)
+	throws UnsupportedCommOperationException
+	{
+		if (debug) System.out.println(
+			"RXTXPort:setSerialPortParams(b:" + b + " d:" + d + " s:" + s + " p:" + p + ")"
+		);
 		if ( nativeSetSerialPortParams( b, d, s, p ) )
-			throw new UnsupportedCommOperationException(
-				"Invalid Parameter" );
+		{
+			throw new UnsupportedCommOperationException
+			(
+				"Invalid Parameter" 
+			);
+		}
+		
 		speed = b;
-		if( s== STOPBITS_1_5 ) dataBits = DATABITS_5;
-		else dataBits = d;
+		
+		if( s== STOPBITS_1_5 )
+		{
+			dataBits = DATABITS_5;
+		}
+		else
+		{
+			dataBits = d;
+		}
+		
 		stopBits = s;
 		parity = p;
-			z.reportln( "RXTXPort:setSerialPortParams(" +
-				b + " " + d + " " + s + " " + p +
-				") returning");
+		
+		if (debug) System.out.println(
+			"RXTXPort:setSerialPortParams(b:" + b + " d:" + d + " s:" + s + " p:" + p + "):Exit"
+		);
+		
 	}
 
 	/**
-	*  Set the native serial port parameters
-	*  If speed is not a predifined speed it is assumed to be
-	*  the actual speed desired.
-	*/
-	private native boolean nativeSetSerialPortParams( int speed,
-		int dataBits, int stopBits, int parity )
-		throws UnsupportedCommOperationException;
+	*	Set the native serial port parameters
+	*	If speed is not a predifined speed it is assumed to be
+	*	the actual speed desired.
+	**/
+	private native boolean nativeSetSerialPortParams(
+		int speed,
+		int dataBits,
+		int stopBits,
+		int parity
+	)
+	throws UnsupportedCommOperationException;
 
 	/** Line speed in bits-per-second */
 	private int speed=9600;
+	
 	/** 
-	*  @return  int representing the baudrate
-	*  This will not behave as expected with custom speeds
-	*/
+	*	@return  int representing the baudrate
+	*	This will not behave as expected with custom speeds
+	**/
+	
 	public int getBaudRate()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getBaudRate() called and returning " + speed);
+		{
+			System.out.println(
+				"RXTXPort:getBaudRate:Exit" + speed
+			);
+		}
 		return speed;
 	}
 
-	/** Data bits port parameter */
+	/**
+	* Data bits port parameter 
+	**/
+	
 	private int dataBits=DATABITS_8;
+	
 	/** 
-	*  @return int representing the databits
-	*/
+	*	@return int representing the databits
+	**/
 	public int getDataBits()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getDataBits() called and returning " + dataBits);
+			System.out.println("RXTXPort:getDataBits(" + dataBits + ")");
 		return dataBits;
 	}
 
 	/** Stop bits port parameter */
 	private int stopBits=SerialPort.STOPBITS_1;
+	
 	/** 
-	*  @return int representing the stopbits
-	*/
+	*	@return int representing the stopbits
+	**/
 	public int getStopBits()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getStopBits() called and returning " + stopBits);
+		if (debug) System.out.println( 
+			"RXTXPort:getStopBits(" + stopBits + ")"
+		);
 		return stopBits;
 	}
 
 	/** Parity port parameter */
 	private int parity= SerialPort.PARITY_NONE;
+	
 	/** 
-	*  @return int representing the parity
-	*/
+	*	@return int representing the parity
+	**/
 	public int getParity()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getParity() called and returning " + parity );
+		if (debug) System.out.println(
+			"RXTXPort:getParity(" + parity +")"
+		);
+		
 		return parity;
 	}
 
 
 	/** Flow control */
 	private int flowmode = SerialPort.FLOWCONTROL_NONE;
+	
 	/** 
-	*  @param  flowcontrol FLOWCONTROL_NONE is default
-	*  @see gnu.io.SerialPort#FLOWCONTROL_NONE
-	*/
+	*	@param  flowcontrol FLOWCONTROL_NONE is default
+	*	@see gnu.io.SerialPort#FLOWCONTROL_NONE
+	**/
 	public void setFlowControlMode( int flowcontrol )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:setFlowControlMode( " + flowcontrol + " ) called");
+		if (debug) System.out.println(
+			"RXTXPort:setFlowControlMode(" + flowcontrol + ")"
+		);
+		
 		if(monThreadisInterrupted) 
 		{
-			if( debug_events )
-				z.reportln(  "RXTXPort:setFlowControlMode MonThread is Interrupeted returning" );
+			if (debug_events) System.out.println(
+				"RXTXPort:setFlowControlMode:MonThread Interrupted"
+			);
+			
 			return;
 		}
-		try {
+		
+		try 
+		{
 			setflowcontrol( flowcontrol );
 		}
 		catch( IOException e )
@@ -303,61 +404,75 @@
 			e.printStackTrace();
 			return;
 		}
+		
 		flowmode=flowcontrol;
-		if (debug)
-			z.reportln( "RXTXPort:setFlowControlMode( " + flowcontrol + " ) returning");
+		
+		if (debug) System.out.println(
+			"RXTXPort:setFlowControlMode(" + flowcontrol + " ):Exit"
+		);
 	}
+	
 	/** 
-	*  @return  int representing the flowmode
-	*/
+	*	@return  int representing the flowmode
+	**/
 	public int getFlowControlMode()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getFlowControlMode() returning " + flowmode );
+		if (debug) System.out.println(
+			"RXTXPort:getFlowControlMode(" + flowmode + ")"
+		);
+		
 		return flowmode;
 	}
+	
 	native void setflowcontrol( int flowcontrol ) throws IOException;
 
 
-	/*
-	linux/drivers/char/n_hdlc.c? FIXME
-		taj@www.linux.org.uk
-	*/
 	/**
-	*  Receive framing control
-	*  @param  f framming
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	linux/drivers/char/n_hdlc.c? FIXME
+	*	taj@www.linux.org.uk
+	**/
+	
+	/**
+	*	Receive framing control
+	*	@param	f framming
+	*	@throws	UnsupportedCommOperationException
+	**/
 	public void enableReceiveFraming( int f )
-		throws UnsupportedCommOperationException
+	throws UnsupportedCommOperationException
 	{
-		if (debug)
-			z.reportln( "RXTXPort:enableReceiveFramming() throwing exception");
-		throw new UnsupportedCommOperationException( "Not supported" );
+		if (debug) System.out.println(
+			"RXTXPort:enableReceiveFramming() throwing exception"
+		);
+		
+		throw new UnsupportedCommOperationException("Not supported" );
 	}
-	/** 
-	*/
+	
 	public void disableReceiveFraming()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:disableReceiveFramming() called and returning (noop)");
+		if (debug) System.out.println(
+			"RXTXPort:disableReceiveFramming()"
+		);
 	}
+	
 	/** 
-	*  @return true if framing is enabled
-	*/
+	*	@return true if framing is enabled
+	**/
 	public boolean isReceiveFramingEnabled()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:isReceiveFrammingEnabled() called and returning " + false );
+		if (debug) System.out.println(
+			"RXTXPort:isReceiveFrammingEnabled(" + false +")"
+		);
 		return false;
 	}
 	/** 
-	*  @return  int representing the framing byte
-	*/
+	*	@return  int representing the framing byte
+	**/
 	public int getReceiveFramingByte()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getReceiveFrammingByte() called and returning " + 0 );
+		if (debug) System.out.println(
+			"RXTXPort:getReceiveFrammingByte(0)" 
+		);
+		
 		return 0;
 	}
 
@@ -366,38 +481,49 @@
 	private int timeout;
 
 	/** 
-	*  @return  int the timeout
-	*/
+	*	@return  int the timeout
+	**/
 	public native int NativegetReceiveTimeout();
+	
 	/** 
-	*  @return  bloolean true if recieve timeout is enabled
-	*/
+	*	@return  bloolean true if recieve timeout is enabled
+	**/
 	private native boolean NativeisReceiveTimeoutEnabled();
+	
 	/** 
-	*  @param  time
-	*  @param  threshold
-	*  @param  InputBuffer
-	*/
-	private native void NativeEnableReceiveTimeoutThreshold(int time,
-		int threshold,int InputBuffer);
-	/** 
-	*/
+	*	@param  time
+	*	@param  threshold
+	*	@param  InputBuffer
+	**/
+	private native void NativeEnableReceiveTimeoutThreshold(
+		int time,
+		int threshold,
+		int InputBuffer
+	);
+	
 	public void disableReceiveTimeout()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:disableReceiveTimeout() called");
+		if (debug) System.out.println(
+			"RXTXPort:disableReceiveTimeout()"
+		);
+		
 		timeout = -1;
+		
 		NativeEnableReceiveTimeoutThreshold( timeout , threshold, InputBuffer );
-		if (debug)
-			z.reportln( "RXTXPort:disableReceiveTimeout() returning");
+		
+		if (debug) System.out.println(
+			"RXTXPort:disableReceiveTimeout:Exit"
+		);
 	}
+	
 	/** 
-	*  @param time
-	*/
+	*	@param time
+	**/
 	public void enableReceiveTimeout( int time )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:enableReceiveTimeout() called");
+			System.out.println("RXTXPort:enableReceiveTimeout(" + time + ")");
+			
 		if( time >= 0 )
 		{
 			timeout = time;
@@ -411,25 +537,26 @@
 				"Unexpected negative timeout value"
 			);
 		}
+		
 		if (debug)
-			z.reportln( "RXTXPort:enableReceiveTimeout() returning");
+			System.out.println("RXTXPort:enableReceiveTimeout:Exit");
 	}
 	/** 
-	*  @return  boolean true if recieve timeout is enabled
-	*/
+	*	@return  boolean true if recieve timeout is enabled
+	**/
 	public boolean isReceiveTimeoutEnabled()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:isReceiveTimeoutEnabled() called and returning " + NativeisReceiveTimeoutEnabled() );
+			System.out.println("RXTXPort:isReceiveTimeoutEnabled:Exit" + NativeisReceiveTimeoutEnabled() );
 		return( NativeisReceiveTimeoutEnabled() );
 	}
 	/** 
-	*  @return  int the timeout
-	*/
+	*	@return  int the timeout
+	**/
 	public int getReceiveTimeout()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getReceiveTimeout() called and returning " + NativegetReceiveTimeout() );
+			System.out.println("RXTXPort:getReceiveTimeout:Exit" + NativegetReceiveTimeout() );
 		return(NativegetReceiveTimeout( ));
 	}
 
@@ -438,12 +565,12 @@
 	private int threshold = 0;
 
 	/** 
-	*  @param thresh threshold
-	*/
+	*	@param thresh threshold
+	**/
 	public void enableReceiveThreshold( int thresh )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:enableReceiveThreshold( " + thresh + " ) called");
+			System.out.println("RXTXPort:enableReceiveThreshold(" + thresh + " ) called");
 		if(thresh >=0)
 		{
 			threshold=thresh;
@@ -458,32 +585,32 @@
 			);
 		}
 		if (debug)
-			z.reportln( "RXTXPort:enableReceiveThreshold( " + thresh + " ) returned");
+			System.out.println("RXTXPort:enableReceiveThreshold(" + thresh + " ) returned");
 	}
 	/** 
-	*/
+	**/
 	public void disableReceiveThreshold()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:disableReceiveThreshold() called and returning");
+			System.out.println("RXTXPort:disableReceiveThreshold:Exit");
 		enableReceiveThreshold(0);
 	}
 	/** 
-	*  @return  int the recieve threshold
-	*/
+	*	@return  int the recieve threshold
+	**/
 	public int getReceiveThreshold()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:getReceiveThreshold() called and returning " + threshold);
+			System.out.println("RXTXPort:getReceiveThreshold:Exit" + threshold);
 		return threshold;
 	}
 	/** 
-	*  @return  boolean true if receive threshold is enabled
-	*/
+	*	@return  boolean true if receive threshold is enabled
+	**/
 	public boolean isReceiveThresholdEnabled()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:isReceiveThresholdEnable() called and returning" + (threshold > 0) );
+			System.out.println("RXTXPort:isReceiveThresholdEnable:Exit" + (threshold > 0) );
 		return(threshold>0);
 	}
 
@@ -493,16 +620,17 @@
 		taj@www.linux.org.uk
 
 		These are native stubs...
-	*/
+	**/
 	private int InputBuffer=0;
 	private int OutputBuffer=0;
+	
 	/** 
-	*  @param size
-	*/
+	*	@param size
+	**/
 	public void setInputBufferSize( int size )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:setInputBufferSize( " +
+			System.out.println("RXTXPort:setInputBufferSize(" +
 					size + ") called");
 		if( size < 0 )
 			throw new IllegalArgumentException
@@ -511,103 +639,139 @@
 			);
 		else InputBuffer=size;
 		if (debug)
-			z.reportln( "RXTXPort:setInputBufferSize( " +
+			System.out.println("RXTXPort:setInputBufferSize(" +
 					size + ") returning");
 	}
-	/** 
-	*/
+
 	public int getInputBufferSize()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getInputBufferSize() called and returning " + InputBuffer );
+		if (debug) System.out.println(
+			"RXTXPort:getInputBufferSize(" + InputBuffer +")"
+		);
 		return(InputBuffer);
 	}
+	
 	/** 
-	*  @param size
-	*/
+	*	@param size
+	**/
 	public void setOutputBufferSize( int size )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:setOutputBufferSize( " +
-					size + ") called");
+		if (debug) System.out.println(
+			"RXTXPort:setOutputBufferSize(" + size + ") called"
+		);
+		
 		if( size < 0 )
-			throw new IllegalArgumentException
-			(
-				"Unexpected negative buffer size value"
-			);
-		else OutputBuffer=size;
-		if (debug)
-			z.reportln( "RXTXPort:setOutputBufferSize( " +
-					size + ") returned");
+		{
+		throw new IllegalArgumentException
+		(
+			"Unexpected negative buffer size value"
+		);
+		}
+		else
+		{
+			OutputBuffer=size;
+		}
+		
+		if (debug) System.out.println(
+			"RXTXPort:setOutputBufferSize(" + size + "):Exit"
+		);
 		
 	}
+
 	/** 
-	*  @return  in the output buffer size
-	*/
+	*	@return  in the output buffer size
+	**/
 	public int getOutputBufferSize()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:getOutputBufferSize() called and returning " + OutputBuffer );
+		if (debug) System.out.println(
+			"RXTXPort:getOutputBufferSize(" + OutputBuffer + ")"
+		);
 		return(OutputBuffer);
 	}
 
-	/* =================== cleaned messages to here */
+	/**
+	*	=================== cleaned messages to here
+	**/
 
 	/**
-	*  Line status methods
-	*/
+	*	Line status methods
+	**/
 	/**
-	*  @return true if DTR is set
-	*/
+	*	@return true if DTR is set
+	**/
 	public native boolean isDTR();
+	
 	/** 
-	*  @param state
-	*/
+	*	@param state
+	**/
 	public native void setDTR( boolean state );
+	
 	/** 
-	*  @param state
-	*/
+	*	@param state
+	**/
 	public native void setRTS( boolean state );
 	private native void setDSR( boolean state );
+	
 	/** 
-	*  @return boolean true if CTS is set
-	*/
+	*	@return boolean true if CTS is set
+	**/
 	public native boolean isCTS();
 	/** 
-	*  @return boolean true if DSR is set
-	*/
+	*	@return boolean true if DSR is set
+	**/
 	public native boolean isDSR();
 	/** 
-	*  @return boolean true if CD is set
-	*/
+	*	@return boolean true if CD is set
+	**/
 	public native boolean isCD();
 	/** 
-	*  @return boolean true if RI is set
-	*/
+	*	@return boolean true if RI is set
+	**/
 	public native boolean isRI();
 	/** 
-	*  @return boolean true if RTS is set
-	*/
+	*	@return boolean true if RTS is set
+	**/
 	public native boolean isRTS();
 
 
 	/**
-	*  Write to the port
-	*  @param duration
-	*/
+	*	Write to the port
+	*	@param duration
+	**/
 	public native void sendBreak( int duration );
-	protected native void writeByte( int b, boolean i ) throws IOException;
-	protected native void writeArray( byte b[], int off, int len, boolean i )
-		throws IOException;
-	protected native boolean nativeDrain( boolean i ) throws IOException;
+	
+	protected native void writeByte(
+		int b,
+		boolean i
+	) throws IOException;
+	
+	protected native void writeArray(
+		byte b[],
+		int off,
+		int len,
+		boolean i
+	) throws IOException;
+	
+	protected native boolean nativeDrain(
+		boolean i
+	) throws IOException;
 
 	/** RXTXPort read methods */
 	protected native int nativeavailable() throws IOException;
 	protected native int readByte() throws IOException;
-	protected native int readArray( byte b[], int off, int len )
-		throws IOException;
-	protected native int readTerminatedArray( byte b[], int off, int len, byte t[] )
-		throws IOException;
+	
+	protected native int readArray(
+		byte b[],
+		int off,
+		int len
+	) throws IOException;
+		
+	protected native int readTerminatedArray(
+		byte b[],
+		int off,
+		int len,
+		byte t[]
+	) throws IOException;
 
 
 	/** Serial Port Event listener */
@@ -620,37 +784,43 @@
 	native void eventLoop();
 
 	/** 
-	*  @return boolean  true if monitor thread is interrupted
-	*/
+	*	@return boolean  true if monitor thread is interrupted
+	**/
 	boolean monThreadisInterrupted=true;
-	private native void interruptEventLoop( );
+	
+	private native void interruptEventLoop();
+	
 	public boolean checkMonitorThread()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:checkMonitorThread()");
+		if (debug) System.out.println("RXTXPort:checkMonitorThread()");
 		if(monThread != null)
 		{
-			if ( debug )
-				z.reportln( 
-					"monThreadisInterrupted = " +
-					monThreadisInterrupted );
+			if (debug) System.out.println( 
+				" monThreadisInterrupted = " + monThreadisInterrupted
+			);
+			
 			return monThreadisInterrupted;
 		}
-		if ( debug )
-			z.reportln(  "monThread is null " );
+		
+		if ( debug ) System.out.println(
+			"RXTXPort:checkMonitorThread(null):Exit"
+		);
+			
 		return(true);
 	}
 
 	/** 
-	*  @param event
-	*  @param state
-	*  @return boolean true if the port is closing
-	*/
+	*	@param event
+	*	@param state
+	*	@return boolean true if the port is closing
+	**/
 	public boolean sendEvent( int event, boolean state )
 	{
 		if (debug_events)
-			z.report( "RXTXPort:sendEvent(");
-		/* Let the native side know its time to die */
+			z.report("RXTXPort:sendEvent(");
+		/**
+		*	Let the native side know its time to die
+		**/
 
 		if ( fd == 0 || SPEventListener == null || monThread == null)
 		{
@@ -661,63 +831,63 @@
 		{
 			case SerialPortEvent.DATA_AVAILABLE:
 				if( debug_events )
-					z.reportln( "DATA_AVAILABLE " +
+					System.out.println(" DATA_AVAILABLE " +
 						monThread.Data + ")" );
 				break;
 			case SerialPortEvent.OUTPUT_BUFFER_EMPTY:
 				if( debug_events )
-					z.reportln( 
-						"OUTPUT_BUFFER_EMPTY " +
+					System.out.println( 
+						" OUTPUT_BUFFER_EMPTY " +
 						monThread.Output + ")" );
 				break;
 			case SerialPortEvent.CTS:
 				if( debug_events )
-					z.reportln( "CTS " +
+					System.out.println(" CTS " +
 						monThread.CTS + ")" );
 				break;
 			case SerialPortEvent.DSR:
 				if( debug_events )
-					z.reportln( "DSR " +
+					System.out.println(" DSR " +
 						monThread.Output + ")" );
 				break;
 			case SerialPortEvent.RI:
 				if( debug_events )
-					z.reportln( "RI " +
+					System.out.println(" RI " +
 						monThread.RI + ")" );
 				break;
 			case SerialPortEvent.CD:
 				if( debug_events )
-					z.reportln( "CD " +
+					System.out.println(" CD " +
 						monThread.CD + ")" );
 				break;
 			case SerialPortEvent.OE:
 				if( debug_events )
-					z.reportln( "OE " +
+					System.out.println(" OE " +
 						monThread.OE + ")" );
 				break;
 			case SerialPortEvent.PE:
 				if( debug_events )
-					z.reportln( "PE " +
+					System.out.println(" PE " +
 						monThread.PE + ")" );
 				break;
 			case SerialPortEvent.FE:
 				if( debug_events )
-					z.reportln( "FE " +
+					System.out.println(" FE " +
 						monThread.FE + ")" );
 				break;
 			case SerialPortEvent.BI:
 				if( debug_events )
-					z.reportln( "BI " +
+					System.out.println(" BI " +
 						monThread.BI + ")" );
 				break;
 			default:
 				if( debug_events )
-					z.reportln( "XXXXXXXXXXXXXX " +
+					System.out.println(" XXXXXXXXXXXXXX (" +
 						event + ")" );
 				break;
 		}
 		if( debug_events && debug_verbose )
-			z.reportln(  "	checking flags " );
+			System.out.println(  "	checking flags " );
 
 		switch( event )
 		{
@@ -752,19 +922,19 @@
 				if( monThread.BI ) break;
 				return(false);
 			default:
-				System.err.println( "unknown event: " + event);
+				System.err.println(" unknown event: " + event);
 				return(false);
 		}
 		if( debug_events && debug_verbose )
-			z.reportln(  "	getting event" );
+			System.out.println(  " getting event" );
 		SerialPortEvent e = new SerialPortEvent(this, event, !state,
 			state );
 		if( debug_events && debug_verbose )
-			z.reportln(  "	sending event" );
+			System.out.println(  " sending event" );
 		if(monThreadisInterrupted) 
 		{
 			if( debug_events )
-				z.reportln(  "	sendEvent return" );
+				System.out.println(  " sendEvent return" );
 			return(true);
 		}
 		if( SPEventListener != null )
@@ -773,7 +943,7 @@
 		}
 
 		if( debug_events && debug_verbose )
-			z.reportln(  "	sendEvent return" );
+			System.out.println(  " sendEvent return" );
 
 		if (fd == 0 ||  SPEventListener == null || monThread == null) 
 		{
@@ -786,22 +956,22 @@
 	}
 
 	/**
-	*  Add an event listener
-	*  @param lsnr SerialPortEventListener
-	*  @throws TooManyListenersException
-	*/
+	*	Add an event listener
+	*	@param lsnr SerialPortEventListener
+	*	@throws TooManyListenersException
+	**/
 
 	boolean MonitorThreadLock = true;
 
 	public void addEventListener(
 		SerialPortEventListener lsnr ) throws TooManyListenersException
 	{
-		/*  Don't let and notification requests happen until the
+		/*	Don't let and notification requests happen until the
 		    Eventloop is ready
-		*/
+		**/
 
 		if (debug)
-			z.reportln( "RXTXPort:addEventListener()");
+			System.out.println("RXTXPort:addEventListener()");
 		if( SPEventListener != null )
 		{
 			throw new TooManyListenersException();
@@ -816,54 +986,66 @@
 			MonitorThreadAlive=true;
 		}
 		if (debug)
-			z.reportln( "RXTXPort:Interrupt=false");
+			System.out.println("RXTXPort:addEventListener:Exit");
 	}
+	
 	/**
-	*  Remove the serial port event listener
-	*/
+	*	Remove the serial port event listener
+	**/
 	public void removeEventListener()
 	{
 		if (debug)
-			z.reportln( "RXTXPort:removeEventListener() called");
+			System.out.println("RXTXPort:removeEventListener()");
+		
 		waitForTheNativeCodeSilly();
 		//if( monThread != null && monThread.isAlive() )
+		
 		if( monThreadisInterrupted == true )
 		{
-			z.reportln( "	RXTXPort:removeEventListener() already interrupted");
+			System.out.println(" already interrupted");
 			monThread = null;
 			SPEventListener = null;
 			return;
 		}
 		else if( monThread != null && monThread.isAlive() )
 		{
-			if (debug)
-				z.reportln( "	RXTXPort:Interrupt=true");
+			if (debug) System.out.println(" Interrupt=true");
 			monThreadisInterrupted=true;
-			/*
-			   Notify all threads in this PID that something is up
-			   They will call back to see if its their thread
-			   using isInterrupted().
-			*/
-			if (debug)
-				z.reportln( "	RXTXPort:calling interruptEventLoop");
-			interruptEventLoop( );
 			
-			if (debug)
-				z.reportln( "	RXTXPort:calling monThread.join()");
+			/**
+			*	Notify all threads in this PID that something is up
+			*	They will call back to see if its their thread
+			*	using isInterrupted().
+			**/
+			
+			if (debug) System.out.println(" RXTXPort:removeEventListener - interruptEventLoop");
+			/** 
+			* JCE - On FreeBSD 10.1-p9 this causes a Java Core Dump if port is closed before init sleep has completed
+			**/
+			interruptEventLoop();
+			
+			if (debug) System.out.println(" RXTXPort:removeEventListener - monThread.join()");
+			
 			try {
 
 				// wait a reasonable moment for the death of the monitor thread
 				monThread.join(3000);
-			} catch (InterruptedException ex) {
+				if (debug) System.out.println(" RXTXPort:removeEventListener - Post monThread.join()");	
+			} 
+			catch (InterruptedException ex) 
+			{
 				// somebody called interrupt() on us (ie wants us to abort)
 				// we dont propagate InterruptedExceptions so lets re-set the flag 
+				if (debug) System.out.println(" RXTXPort:removeEventListener - InterruptedException");	
 				Thread.currentThread().interrupt();
 				return;
  			}
+ 			
+			if (debug) System.out.println(" RXTXPort:removeEventListener - Waited!");	
 				
 			if ( debug && monThread.isAlive() )
 			{
-				z.reportln( "	MonThread is still alive!");
+				System.out.println(" MonThread is still alive!");
 
 			}
 			
@@ -873,7 +1055,7 @@
 		MonitorThreadLock = false;
 		MonitorThreadAlive=false;
 		monThreadisInterrupted=true;
-		z.reportln( "RXTXPort:removeEventListener() returning");
+		System.out.println("RXTXPort:removeEventListener:Exit");
 	}
 	/**
 	 *	Give the native code a chance to start listening to the hardware
@@ -894,15 +1076,15 @@
 		}
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	private native void nativeSetEventFlag( int fd, int event,
 						boolean flag );
 	public void notifyOnDataAvailable( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnDataAvailable( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnDataAvailable(" +
+				enable+")");
 		
 		waitForTheNativeCodeSilly();
 
@@ -911,155 +1093,172 @@
 					enable );
 		monThread.Data = enable;
 		MonitorThreadLock = false;
+		if (debug)
+			System.out.println("RXTXPort:notifyOnDataAvailable:Exit");
+		
 	}
 
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnOutputEmpty( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnOutputEmpty( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnOutputEmpty(" +
+				enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.OUTPUT_BUFFER_EMPTY,
 					enable );
 		monThread.Output = enable;
 		MonitorThreadLock = false;
+		if (debug)
+			System.out.println("RXTXPort:notifyOnOutputEmpty:Exit");
+
 	}
 
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnCTS( boolean enable )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:notifyOnCTS( " +
-				enable+" )");
+		if (debug) System.out.println("RXTXPort:notifyOnCTS(" + enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.CTS, enable );
 		monThread.CTS = enable;
 		MonitorThreadLock = false;
+		if (debug) System.out.println("RXTXPort:notifyOnCTS:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnDSR( boolean enable )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:notifyOnDSR( " +
-				enable+" )");
+		if (debug) System.out.println("RXTXPort:notifyOnDSR(" + enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.DSR, enable );
 		monThread.DSR = enable;
 		MonitorThreadLock = false;
+		if (debug) System.out.println("RXTXPort:notifyOnDSR:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnRingIndicator( boolean enable )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:notifyOnRingIndicator( " +
-				enable+" )");
+		if (debug) System.out.println("RXTXPort:notifyOnRingIndicator(" +
+			enable+")");
+				
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.RI, enable );
 		monThread.RI = enable;
 		MonitorThreadLock = false;
+		if (debug) System.out.println("RXTXPort:notifyOnRingIndicator:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnCarrierDetect( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnCarrierDetect( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnCarrierDetect(" +
+				enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.CD, enable );
 		monThread.CD = enable;
 		MonitorThreadLock = false;
+		if (debug)
+			System.out.println("RXTXPort:notifyOnCarrierDetect:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnOverrunError( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnOverrunError( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnOverrunError(" +
+				enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.OE, enable );
 		monThread.OE = enable;
 		MonitorThreadLock = false;
+		if (debug)
+			System.out.println("RXTXPort:notifyOnOverrunError:Exit");
 	}
+	
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnParityError( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnParityError( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnParityError(" +
+				enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.PE, enable );
 		monThread.PE = enable;
 		MonitorThreadLock = false;
+		if (debug)
+			System.out.println("RXTXPort:notifyOnParityError:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnFramingError( boolean enable )
 	{
-		if (debug)
-			z.reportln( "RXTXPort:notifyOnFramingError( " +
-				enable+" )");
+		if (debug) System.out.println("RXTXPort:notifyOnFramingError(" +
+			enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.FE, enable );
 		monThread.FE = enable;
 		MonitorThreadLock = false;
+		if (debug) System.out.println("RXTXPort:notifyOnFramingError:Exit");
 	}
 	/**
-	*  @param enable
-	*/
+	*	@param enable
+	**/
 	public void notifyOnBreakInterrupt( boolean enable )
 	{
 		if (debug)
-			z.reportln( "RXTXPort:notifyOnBreakInterrupt( " +
-				enable+" )");
+			System.out.println("RXTXPort:notifyOnBreakInterrupt(" +
+				enable+")");
 		waitForTheNativeCodeSilly();
 		MonitorThreadLock = true;
 		nativeSetEventFlag( fd, SerialPortEvent.BI, enable );
 		monThread.BI = enable;
 		MonitorThreadLock = false;
+		System.out.println("RXTXPort:notifyOnBreakInterrupt:Exit");
 	}
 
 	/** Close the port */
 	private native void nativeClose( String name );
 	/**
-	*/
+	**/
 	boolean closeLock = false;
 	public void close()
 	{
-		synchronized (this) {
-			if (debug)
-				z.reportln( "RXTXPort:close( " + this.name + " )"); 
-
+		if (debug) System.out.println("RXTXPort:close(" + this.name + ")");
+		
+		synchronized (this) 
+		{
+		
 			while( IOLocked > 0 )
 			{
-				if( debug )
-					z.reportln("IO is locked " + IOLocked);
-				try {
+				if (debug) System.out.println("IO is locked " + IOLocked);
+				
+				try 
+				{
 					this.wait(500);
-				} catch( InterruptedException ie ) {
+				}
+				catch( InterruptedException ie )
+				{
 					// somebody called interrupt() on us
 					// we obbey and return without without closing the socket
 					Thread.currentThread().interrupt();
@@ -1075,55 +1274,62 @@
 
 		if ( fd <= 0 )
 		{
-			z.reportln(  "RXTXPort:close detected bad File Descriptor" );
+			System.out.println(  "RXTXPort:close detected bad File Descriptor" );
 			return;
 		}
+		
 		setDTR(false);
 		setDSR(false);
+		
 		if (debug)
-			z.reportln( "RXTXPort:close( " + this.name + " ) setting monThreadisInterrupted"); 
+			System.out.println("RXTXPort:close(" + this.name + ") setting monThreadisInterrupted"); 
+			
 		if ( ! monThreadisInterrupted )
 		{
 			removeEventListener();
 		}
+		
 		if (debug)
-			z.reportln( "RXTXPort:close( " + this.name + " ) calling nativeClose"); 
+			System.out.println("RXTXPort:close(" + this.name + ") calling nativeClose"); 
 		nativeClose( this.name );
+		
 		if (debug)
-			z.reportln( "RXTXPort:close( " + this.name + " ) calling super.close"); 
+			System.out.println("RXTXPort:close(" + this.name + ") calling super.close"); 
 		super.close();
+		
 		fd = 0;
 		closeLock = false;
 		if (debug)
-			z.reportln( "RXTXPort:close( " + this.name + " ) leaving"); 
+			System.out.println("RXTXPort:close(" + this.name + "):Exit"); 
 	}
 
 
 	/** Finalize the port */
 	protected void finalize()
 	{
-		if (debug)
-			z.reportln( "RXTXPort:finalize()");
+		if (debug) System.out.println("RXTXPort:finalize()");
 		if( fd > 0 )
 		{
 			if (debug)
-				z.reportln( "RXTXPort:calling close()");
+				System.out.println("RXTXPort:calling close()");
 			close();
 		}
 		z.finalize();
+		
+		if (debug) System.out.println("RXTXPort:finalize()");
 	}
 
 	/** Inner class for SerialOutputStream */
 	class SerialOutputStream extends OutputStream
 	{
 	/**
-	*  @param b
-	*  @throws IOException
-	*/
+	*	@param b
+	*	@throws IOException
+	**/
 		public void write( int b ) throws IOException
 		{
 			if (debug_write)
-				z.reportln( "RXTXPort:SerialOutputStream:write(int)");
+				System.out.println("RXTXPort:SerialOutputStream:write("+ b +")");
 			if( speed == 0 ) return;
 			if ( monThreadisInterrupted == true )
 			{
@@ -1140,7 +1346,7 @@
 				}
 				writeByte( b, monThreadisInterrupted );
 				if (debug_write)
-					z.reportln( "Leaving RXTXPort:SerialOutputStream:write( int )");
+					System.out.println("RXTXPort:SerialOutputStream:write(" + b + "):Exit");
 			} finally {
 				synchronized (IOLockedMutex) {
 					IOLocked--;
@@ -1148,15 +1354,16 @@
 			}
 		}
 	/**
-	*  @param b[]
-	*  @throws IOException
-	*/
+	*	@param b[]
+	*	@throws IOException
+	**/
 		public void write( byte b[] ) throws IOException
 		{
 			if (debug_write)
 			{
-				z.reportln( "Entering RXTXPort:SerialOutputStream:write(" + b.length + ") "/* + new String(b)*/ );
+				System.out.println("RXTXPort:SerialOutputStream:write(" + b.length + ")" /* + new String(b)*/ );
 			}
+			
 			if( speed == 0 ) return;
 			if ( monThreadisInterrupted == true )
 			{
@@ -1170,7 +1377,7 @@
 				waitForTheNativeCodeSilly();
 				writeArray( b, 0, b.length, monThreadisInterrupted );
 				if (debug_write)
-					z.reportln( "Leaving RXTXPort:SerialOutputStream:write(" +b.length  +")");
+					System.out.println("RXTXPort:SerialOutputStream:write(" +b.length  +"):Exit");
 			} finally {
 				synchronized(IOLockedMutex) {
 					IOLocked--;
@@ -1179,14 +1386,19 @@
 			
 		}
 	/**
-	*  @param b[]
-	*  @param off
-	*  @param len
-	*  @throws IOException
-	*/
+	*	@param b[]
+	*	@param off
+	*	@param len
+	*	@throws IOException
+	**/
 		public void write( byte b[], int off, int len )
 			throws IOException
 		{
+			if (debug_write)
+			{
+				System.out.println("RXTXPort:SerialOutputStream:write(o:" + off + " l:" + len + ") " /*+  new String(send) */ );
+			}
+			
 			if( speed == 0 ) return;
 			if( off + len  > b.length )
 			{
@@ -1197,10 +1409,7 @@
 	 
 			byte send[] = new byte[len];
 			System.arraycopy( b, off, send, 0, len );
-			if (debug_write)
-			{
-				z.reportln( "Entering RXTXPort:SerialOutputStream:write(" + send.length + " " + off + " " + len + " " +") " /*+  new String(send) */ );
-			}
+			
 			if ( fd == 0 ) throw new IOException();
 			if ( monThreadisInterrupted == true )
 			{
@@ -1214,7 +1423,7 @@
 				waitForTheNativeCodeSilly();
 				writeArray( send, 0, len, monThreadisInterrupted );
 				if( debug_write )
-					z.reportln( "Leaving RXTXPort:SerialOutputStream:write(" + send.length + " " + off + " " + len + " " +") "  /*+ new String(send)*/ );
+					System.out.println("Leaving RXTXPort:SerialOutputStream:write(" + send.length + " " + off + " " + len + " " +") "  /*+ new String(send)*/ );
 			} finally {
 				synchronized (IOLockedMutex) {
 					IOLocked--;
@@ -1222,17 +1431,17 @@
 			}
 		}
 	/**
-	*/
+	**/
 		public void flush() throws IOException
 		{
 			if (debug)
-				z.reportln( "RXTXPort:SerialOutputStream:flush() enter");
+				System.out.println("RXTXPort:SerialOutputStream:flush()");
 			if( speed == 0 ) return;
 			if ( fd == 0 ) throw new IOException();
 			if ( monThreadisInterrupted == true )
 			{
 			if (debug)
-				z.reportln( "RXTXPort:SerialOutputStream:flush() Leaving Interrupted");
+				System.out.println("RXTXPort:SerialOutputStream:flush():Exit - Interrupted");
 				return;
 			}
 			synchronized(IOLockedMutex) {
@@ -1244,17 +1453,19 @@
 				/* 
 				   this is probably good on all OS's but for now
 				   just sendEvent from java on Sol
-				*/
+				**/
 				if ( nativeDrain( monThreadisInterrupted ) )
 					sendEvent( SerialPortEvent.OUTPUT_BUFFER_EMPTY, true );
 				if (debug)
-					z.reportln( "RXTXPort:SerialOutputStream:flush() leave");
+					System.out.println("RXTXPort:SerialOutputStream:flush():EndTry");
 			}
 			finally
 			{
 				synchronized (IOLockedMutex) {
 					IOLocked--;
 				}
+				if (debug)
+					System.out.println("RXTXPort:SerialOutputStream:flush():Exit");
 			}
 		}
 	}
@@ -1263,42 +1474,42 @@
 	class SerialInputStream extends InputStream
 	{
 	/**
-	*  @return int the int read
-	*  @throws IOException
-	*  @see java.io.InputStream
+	*	@return int the int read
+	*	@throws IOException
+	*	@see java.io.InputStream
 *
 *timeout threshold       Behavior
 *------------------------------------------------------------------------
 *0       0       blocks until 1 byte is available timeout > 0,
-*                threshold = 0, blocks until timeout occurs, returns -1
-*                on timeout
+*	              threshold = 0, blocks until timeout occurs, returns -1
+*	              on timeout
 *>0      >0      blocks until timeout, returns - 1 on timeout, magnitude
-*                of threshold doesn't play a role.
+*	              of threshold doesn't play a role.
 *0       >0      Blocks until 1 byte, magnitude of  threshold doesn't
-*                play a role
-	*/
+*	              play a role
+	**/
 		public synchronized int read() throws IOException
 		{
 			if (debug_read)
-				z.reportln( "RXTXPort:SerialInputStream:read() called");
+				System.out.println("RXTXPort:SerialInputStream:read()");
 			if ( fd == 0 ) throw new IOException();
 			if ( monThreadisInterrupted )
 			{
-				z.reportln( "+++++++++ read() monThreadisInterrupted" );
+				System.out.println("+++++++++ read() monThreadisInterrupted" );
 			}
 			synchronized (IOLockedMutex) {
 				IOLocked++;
 			}
 			try {
 				if (debug_read_results)
-					z.reportln(  "RXTXPort:SerialInputStream:read() L" );
+					System.out.println(  "RXTXPort:SerialInputStream:read() L" );
 				waitForTheNativeCodeSilly();
 				if (debug_read_results)
-					z.reportln(  "RXTXPort:SerialInputStream:read() N" );
+					System.out.println(  "RXTXPort:SerialInputStream:read() N" );
 				int result = readByte();
 				if (debug_read_results)
-					//z.reportln(  "RXTXPort:SerialInputStream:read() returns byte = " + result );
-					z.reportln(  "RXTXPort:SerialInputStream:read() returns" );
+					//System.out.println(  "RXTXPort:SerialInputStream:read() returns byte = " + result );
+					System.out.println(  "RXTXPort:SerialInputStream:read() returns" );
 				return( result );
 			}				
 			finally
@@ -1309,9 +1520,9 @@
 			}
 		}
 	/**
-	*  @param b[]
-	*  @return int  number of bytes read
-	*  @throws IOException
+	*	@param b[]
+	*	@return int  number of bytes read
+	*	@throws IOException
 *
 *timeout threshold       Behavior
 *------------------------------------------------------------------------
@@ -1320,12 +1531,12 @@
 *>0      >0      blocks until timeout or reads threshold bytes,
                  returns 0 on timeout
 *0       >0      blocks until reads threshold bytes
-	*/
+	**/
 		public synchronized int read( byte b[] ) throws IOException
 		{
 			int result;
 			if (debug_read)
-				z.reportln( "RXTXPort:SerialInputStream:read(" + b.length + ") called");
+				System.out.println("RXTXPort:SerialInputStream:read(" + b.length + ") called");
 			if ( monThreadisInterrupted == true )
 			{
 				return(0);
@@ -1338,7 +1549,7 @@
 				waitForTheNativeCodeSilly();
 				result = read( b, 0, b.length);
 				if (debug_read_results)
-					z.reportln(  "RXTXPort:SerialInputStream:read() returned " + result + " bytes" );
+					System.out.println(  "RXTXPort:SerialInputStream:read() returned " + result + " bytes" );
 				return( result );
 			}
 			finally
@@ -1353,11 +1564,11 @@
 Documentation is at http://java.sun.com/products/jdk/1.2/docs/api/java/io/InputStream.html#read(byte[], int, int)
 */
 	/**
-	*  @param b[]
-	*  @param off
-	*  @param len
-	*  @return int  number of bytes read
-	*  @throws IOException
+	*	@param b[]
+	*	@param off
+	*	@param len
+	*	@return int  number of bytes read
+	*	@throws IOException
 *
 *timeout threshold       Behavior
 *------------------------------------------------------------------------
@@ -1367,12 +1578,12 @@
                  returns 0 on timeout
 *0       >0      blocks until either threshold # of bytes or len bytes,
                  whichever was lower.
-	*/
+	**/
 		public synchronized int read( byte b[], int off, int len )
 			throws IOException
 		{
 			if (debug_read)
-				z.reportln( "RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") called" /*+ new String(b) */ );
+				System.out.println("RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") called" /*+ new String(b) */ );
 			int result;
 			/*
 			 * Some sanity checks
@@ -1380,24 +1591,24 @@
 			if ( fd == 0 )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() fd == 0");
-				z.reportln("+++++++ IOException()\n");
+					System.out.println("RXTXPort:SerialInputStream:read() fd == 0");
+				System.out.println("+++++++ IOException()\n");
 				throw new IOException();
 			}
 
 			if( b==null )
 			{
-				z.reportln("+++++++ NullPointerException()\n");
+				System.out.println("+++++++ NullPointerException()\n");
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() b == 0");
+					System.out.println("RXTXPort:SerialInputStream:read() b == 0");
 				throw new NullPointerException();
 			}
 
 			if( (off < 0) || (len < 0) || (off+len > b.length))
 			{
-				z.reportln("+++++++ IndexOutOfBoundsException()\n");
+				System.out.println("+++++++ IndexOutOfBoundsException()\n");
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() off < 0 ..");
+					System.out.println("RXTXPort:SerialInputStream:read() off < 0 ..");
 				throw new IndexOutOfBoundsException();
 			}
 
@@ -1407,7 +1618,7 @@
 			if( len==0 )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() off < 0 ..");
+					System.out.println("RXTXPort:SerialInputStream:read() off < 0 ..");
 				return 0;
 			}
 			/*
@@ -1442,7 +1653,7 @@
 			if ( monThreadisInterrupted == true )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() Interrupted");
+					System.out.println("RXTXPort:SerialInputStream:read() Interrupted");
 				return(0);
 			}
 			synchronized (IOLockedMutex) {
@@ -1453,7 +1664,7 @@
 				waitForTheNativeCodeSilly();
 				result = readArray( b, off, Minimum);
 				if (debug_read_results)
-					z.reportln( "RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") returned " + result + " bytes"  /*+ new String(b) */);
+					System.out.println("RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") returned " + result + " bytes"  /*+ new String(b) */);
 				return( result );
 			}
 			finally
@@ -1465,12 +1676,12 @@
 		}
 
 	/**
-	*  @param b[]
-	*  @param off
-	*  @param len
-	*  @param t[]
-	*  @return int  number of bytes read
-	*  @throws IOException
+	*	@param b[]
+	*	@param off
+	*	@param len
+	*	@param t[]
+	*	@return int  number of bytes read
+	*	@throws IOException
 
 	   We are trying to catch the terminator in the native code
 	   Right now it is assumed that t[] is an array of 2 bytes.
@@ -1479,13 +1690,13 @@
 	   array will contain the terminator.  Otherwise read behavior should
 	   be the same as read( b[], off, len ).  Timeouts have not been well
 	   tested.
-	*/
+	**/
 
 		public synchronized int read( byte b[], int off, int len, byte t[] )
 			throws IOException
 		{
 			if (debug_read)
-				z.reportln( "RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") called" /*+ new String(b) */ );
+				System.out.println("RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") called" /*+ new String(b) */ );
 			int result;
 			/*
 			 * Some sanity checks
@@ -1493,24 +1704,24 @@
 			if ( fd == 0 )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() fd == 0");
-				z.reportln("+++++++ IOException()\n");
+					System.out.println("RXTXPort:SerialInputStream:read() fd == 0");
+				System.out.println("+++++++ IOException()\n");
 				throw new IOException();
 			}
 
 			if( b==null )
 			{
-				z.reportln("+++++++ NullPointerException()\n");
+				System.out.println("+++++++ NullPointerException()\n");
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() b == 0");
+					System.out.println("RXTXPort:SerialInputStream:read() b == 0");
 				throw new NullPointerException();
 			}
 
 			if( (off < 0) || (len < 0) || (off+len > b.length))
 			{
-				z.reportln("+++++++ IndexOutOfBoundsException()\n");
+				System.out.println("+++++++ IndexOutOfBoundsException()\n");
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() off < 0 ..");
+					System.out.println("RXTXPort:SerialInputStream:read() off < 0 ..");
 				throw new IndexOutOfBoundsException();
 			}
 
@@ -1520,7 +1731,7 @@
 			if( len==0 )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() off < 0 ..");
+					System.out.println("RXTXPort:SerialInputStream:read() off < 0 ..");
 				return 0;
 			}
 			/*
@@ -1555,7 +1766,7 @@
 			if ( monThreadisInterrupted == true )
 			{
 				if (debug_read)
-					z.reportln( "RXTXPort:SerialInputStream:read() Interrupted");
+					System.out.println("RXTXPort:SerialInputStream:read() Interrupted");
 				return(0);
 			}
 			synchronized (IOLockedMutex) {
@@ -1566,7 +1777,7 @@
 				waitForTheNativeCodeSilly();
 				result = readTerminatedArray( b, off, Minimum, t );
 				if (debug_read_results)
-					z.reportln( "RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") returned " + result + " bytes"  /*+ new String(b) */);
+					System.out.println("RXTXPort:SerialInputStream:read(" + b.length + " " + off + " " + len + ") returned " + result + " bytes"  /*+ new String(b) */);
 				return( result );
 			}
 			finally
@@ -1577,9 +1788,9 @@
 			}
 		}
 	/**
-	*  @return int bytes available
-	*  @throws IOException
-	*/
+	*	@return int bytes available
+	*	@throws IOException
+	**/
 		public synchronized int available() throws IOException
 		{
 			if ( monThreadisInterrupted == true )
@@ -1587,7 +1798,7 @@
 				return(0);
 			}
 			if ( debug_verbose )
-				z.reportln( "RXTXPort:available() called" );
+				System.out.println("RXTXPort:available() called" );
 			synchronized (IOLockedMutex) {
 				IOLocked++;
 			}
@@ -1595,7 +1806,7 @@
 			{
 				int r = nativeavailable();
 				if ( debug_verbose )
-					z.reportln( "RXTXPort:available() returning " +
+					System.out.println("RXTXPort:available() returning " +
 						r );
 				return r;
 			}
@@ -1608,7 +1819,7 @@
 		}
 	}
 	/**
-	*/
+	**/
 	class MonitorThread extends Thread
 	{
 	/** Note: these have to be separate boolean flags because the
@@ -1628,30 +1839,30 @@
 		MonitorThread() 
 		{
 			if (debug)
-				z.reportln( "RXTXPort:MontitorThread:MonitorThread()"); 
+				System.out.println("RXTXPort:MontitorThread:MonitorThread()"); 
 		}
 	/**
-	*  run the thread and call the event loop.
-	*/
+	*	run the thread and call the event loop.
+	**/
 		public void run()
 		{
 			if (debug)
-				z.reportln( "RXTXPort:MontitorThread:run()"); 
+				System.out.println("RXTXPort:MontitorThread:run()"); 
 			monThreadisInterrupted=false;
 			eventLoop();
 			if (debug)
-				z.reportln( "eventLoop() returned"); 
+				System.out.println("eventLoop() returned"); 
 		}
 		protected void finalize() throws Throwable 
 		{ 
 			if (debug)
-				z.reportln( "RXTXPort:MonitorThread exiting"); 
+				System.out.println("RXTXPort:MonitorThread exiting"); 
 		}
 	}
 	/**
-	*  A dummy method added so RXTX compiles on Kaffee
-	*  @deprecated deprecated but used in Kaffe 
-	*/
+	*	A dummy method added so RXTX compiles on Kaffee
+	*	@deprecated deprecated but used in Kaffe 
+	**/
 	public void setRcvFifoTrigger(int trigger){};  
 
 /*------------------------  END OF CommAPI -----------------------------*/
@@ -1724,542 +1935,542 @@
 		throws UnsupportedCommOperationException;
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  This is only accurate up to 38600 baud currently.
-	*
-	*  @param  port the name of the port thats been preopened
-	*  @return BaudRate on success
-	*  @throws UnsupportedCommOperationException;
-	*  This will not behave as expected with custom speeds
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	This is only accurate up to 38600 baud currently.
+	*
+	*	@param  port the name of the port thats been preopened
+	*	@return BaudRate on success
+	*	@throws UnsupportedCommOperationException;
+	*	This will not behave as expected with custom speeds
 	*
-	*/
+	**/
 	public static int staticGetBaudRate( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( 
-				"RXTXPort:staticGetBaudRate( " + port + " )");
+			System.out.println( 
+				"RXTXPort:staticGetBaudRate(" + port + ")");
 		return(nativeStaticGetBaudRate( port ));
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  @param  port the name of the port thats been preopened
-	*  @return DataBits on success
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	@param  port the name of the port thats been preopened
+	*	@return DataBits on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 	public static int staticGetDataBits( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( 
-				"RXTXPort:staticGetDataBits( " + port + " )");
+			System.out.println( 
+				"RXTXPort:staticGetDataBits(" + port + ")");
 		return(nativeStaticGetDataBits( port ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  @param  port the name of the port thats been preopened
-	*  @return Parity on success
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	@param  port the name of the port thats been preopened
+	*	@return Parity on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 	public static int staticGetParity( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( 
-				"RXTXPort:staticGetParity( " + port + " )");
+			System.out.println( 
+				"RXTXPort:staticGetParity(" + port + ")");
 		return( nativeStaticGetParity( port ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  @param  port the name of the port thats been preopened
-	*  @return StopBits on success
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	@param  port the name of the port thats been preopened
+	*	@return StopBits on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 	public static int staticGetStopBits( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( 
-				"RXTXPort:staticGetStopBits( " + port + " )");
+			System.out.println( 
+				"RXTXPort:staticGetStopBits(" + port + ")");
 			return(nativeStaticGetStopBits( port ) );
 	}
 
 	/** 
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  Set the SerialPort parameters
-	*  1.5 stop bits requires 5 databits
-	*  @param  f filename
-	*  @param  b baudrate
-	*  @param  d databits
-	*  @param  s stopbits
-	*  @param  p parity
-	*
-	*  @throws UnsupportedCommOperationException
-	*  @see gnu.io.UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	Set the SerialPort parameters
+	*	1.5 stop bits requires 5 databits
+	*	@param  f filename
+	*	@param  b baudrate
+	*	@param  d databits
+	*	@param  s stopbits
+	*	@param  p parity
+	*
+	*	@throws UnsupportedCommOperationException
+	*	@see gnu.io.UnsupportedCommOperationException
+	**/
 
 	public static void staticSetSerialPortParams( String f, int b, int d,
 		int s, int p )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( 
-				"RXTXPort:staticSetSerialPortParams( " +
+			System.out.println( 
+				"RXTXPort:staticSetSerialPortParams(" +
 				f + " " + b + " " + d + " " + s + " " + p );
 		nativeStaticSetSerialPortParams( f, b, d, s, p );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  Open the port and set DSR.  remove lockfile and do not close
-	*  This is so some software can appear to set the DSR before 'opening'
-	*  the port a second time later on.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	Open the port and set DSR.  remove lockfile and do not close
+	*	This is so some software can appear to set the DSR before 'opening'
+	*	the port a second time later on.
 	*
-	*  @return true on success
-	*  @throws UnsupportedCommOperationException;
+	*	@return true on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticSetDSR( String port, boolean flag )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticSetDSR( " + port +
+			System.out.println(  "RXTXPort:staticSetDSR(" + port +
 						" " + flag );
 		return( nativeStaticSetDSR( port, flag ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  Open the port and set DTR.  remove lockfile and do not close
-	*  This is so some software can appear to set the DTR before 'opening'
-	*  the port a second time later on.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	Open the port and set DTR.  remove lockfile and do not close
+	*	This is so some software can appear to set the DTR before 'opening'
+	*	the port a second time later on.
 	*
-	*  @return true on success
-	*  @throws UnsupportedCommOperationException;
+	*	@return true on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticSetDTR( String port, boolean flag )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticSetDTR( " + port +
+			System.out.println(  "RXTXPort:staticSetDTR(" + port +
 						" " + flag );
 		return( nativeStaticSetDTR( port, flag ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*
-	*  Open the port and set RTS.  remove lockfile and do not close
-	*  This is so some software can appear to set the RTS before 'opening'
-	*  the port a second time later on.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*
+	*	Open the port and set RTS.  remove lockfile and do not close
+	*	This is so some software can appear to set the RTS before 'opening'
+	*	the port a second time later on.
 	*
-	*  @return none
-	*  @throws UnsupportedCommOperationException;
+	*	@return none
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticSetRTS( String port, boolean flag )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticSetRTS( " + port +
+			System.out.println(  "RXTXPort:staticSetRTS(" + port +
 						" " + flag );
 		return( nativeStaticSetRTS( port, flag ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return RTS without using a Java open() call
+	*	find the fd and return RTS without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsRTS( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticIsRTS( " + port + " )" );
+			System.out.println(  "RXTXPort:staticIsRTS(" + port + ")" );
 		return( nativeStaticIsRTS( port ) );
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return CD without using a Java open() call
+	*	find the fd and return CD without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsCD( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln( "RXTXPort:staticIsCD( " + port + " )" );
+			System.out.println("RXTXPort:staticIsCD(" + port + ")" );
 		return( nativeStaticIsCD( port ) );
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return CTS without using a Java open() call
+	*	find the fd and return CTS without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsCTS( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticIsCTS( " + port + " )" );
+			System.out.println(  "RXTXPort:staticIsCTS(" + port + ")" );
 		return( nativeStaticIsCTS( port ) );
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return DSR without using a Java open() call
+	*	find the fd and return DSR without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsDSR( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticIsDSR( " + port + " )" );
+			System.out.println(  "RXTXPort:staticIsDSR(" + port + ")" );
 		return( nativeStaticIsDSR( port ) );
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return DTR without using a Java open() call
+	*	find the fd and return DTR without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsDTR( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticIsDTR( " + port + " )" );
+			System.out.println(  "RXTXPort:staticIsDTR(" + port + ")" );
 		return( nativeStaticIsDTR( port ) );
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
 	*
-	*  find the fd and return RI without using a Java open() call
+	*	find the fd and return RI without using a Java open() call
 	*
-	*  @param port
-	*  @return true if asserted
-	*  @throws UnsupportedCommOperationException;
+	*	@param port
+	*	@return true if asserted
+	*	@throws UnsupportedCommOperationException;
 	*
-	*/
+	**/
 
 	public static boolean staticIsRI( String port )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:staticIsRI( " + port + " )" );
+			System.out.println(  "RXTXPort:staticIsRI(" + port + ")" );
 		return( nativeStaticIsRI( port ) );
 	}
 
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @return int the Parity Error Character
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@return int the Parity Error Character
+	*	@throws UnsupportedCommOperationException;
 	*
-	*  Anyone know how to do this in Unix?
-	*/
+	*	Anyone know how to do this in Unix?
+	**/
 
 	public byte getParityErrorChar( )
 		throws UnsupportedCommOperationException
 	{
 		byte ret;
 		if ( debug )
-			z.reportln(  "getParityErrorChar()" );
+			System.out.println(  "getParityErrorChar()" );
 		ret = nativeGetParityErrorChar();
 		if ( debug )
-			z.reportln(  "getParityErrorChar() returns " +
+			System.out.println(  "getParityErrorChar() returns " +
 						ret );
 		return( ret );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @param b Parity Error Character
-	*  @return boolean true on success
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@param b Parity Error Character
+	*	@return boolean true on success
+	*	@throws UnsupportedCommOperationException;
 	*
-	*  Anyone know how to do this in Unix?
-	*/
+	*	Anyone know how to do this in Unix?
+	**/
 
 	public boolean setParityErrorChar( byte b )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "setParityErrorChar(" + b + ")" );
+			System.out.println(  "setParityErrorChar(" + b + ")" );
 		return( nativeSetParityErrorChar( b ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @return int the End of Input Character
-	*  @throws UnsupportedCommOperationException;
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@return int the End of Input Character
+	*	@throws UnsupportedCommOperationException;
 	*
-	*  Anyone know how to do this in Unix?
-	*/
+	*	Anyone know how to do this in Unix?
+	**/
 
 	public byte getEndOfInputChar( )
 		throws UnsupportedCommOperationException
 	{
 		byte ret;
 		if ( debug )
-			z.reportln(  "getEndOfInputChar()" );
+			System.out.println(  "getEndOfInputChar()" );
 		ret = nativeGetEndOfInputChar();
 		if ( debug )
-			z.reportln(  "getEndOfInputChar() returns " +
+			System.out.println(  "getEndOfInputChar() returns " +
 						ret );
 		return( ret );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @param b End Of Input Character
-	*  @return boolean true on success
-	*  @throws UnsupportedCommOperationException;
-	*/
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@param b End Of Input Character
+	*	@return boolean true on success
+	*	@throws UnsupportedCommOperationException;
+	**/
 
 	public boolean setEndOfInputChar( byte b )
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "setEndOfInputChar(" + b + ")" );
+			System.out.println(  "setEndOfInputChar(" + b + ")" );
 		return( nativeSetEndOfInputChar( b ) );
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @param type String representation of the UART type which mayb
-	*  be "none", "8250", "16450", "16550", "16550A", "16650", "16550V2"
-	*  or "16750".
-	*  @param test boolean flag to determin if the UART should be tested.
-	*  @return boolean true on success
-	*  @throws UnsupportedCommOperationException;
-	*/
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@param type String representation of the UART type which mayb
+	*	be "none", "8250", "16450", "16550", "16550A", "16650", "16550V2"
+	*	or "16750".
+	*	@param test boolean flag to determin if the UART should be tested.
+	*	@return boolean true on success
+	*	@throws UnsupportedCommOperationException;
+	**/
 	public boolean setUARTType(String type, boolean test)
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:setUARTType()");
+			System.out.println(  "RXTXPort:setUARTType()");
 		return nativeSetUartType(type, test);
 	}
 	/**
-	*  Extension to CommAPI
-	*  This is an extension to CommAPI.  It may not be supported on
-	*  all operating systems.
-	*  @return type String representation of the UART type which mayb
-	*  be "none", "8250", "16450", "16550", "16550A", "16650", "16550V2"
-	*  or "16750".
-	*  @throws UnsupportedCommOperationException;
-	*/
+	*	Extension to CommAPI
+	*	This is an extension to CommAPI.  It may not be supported on
+	*	all operating systems.
+	*	@return type String representation of the UART type which mayb
+	*	be "none", "8250", "16450", "16550", "16550A", "16650", "16550V2"
+	*	or "16750".
+	*	@throws UnsupportedCommOperationException;
+	**/
 	public String getUARTType() throws UnsupportedCommOperationException
 	{
 		return nativeGetUartType();
 	}
 
 	/**
-	*  Extension to CommAPI.  Set Baud Base to 38600 on Linux and W32
-	*  before using.
-	*  @param BaudBase The clock frequency divided by 16.  Default
-	*  BaudBase is 115200.
-	*  @return true on success
-	*  @throws UnsupportedCommOperationException, IOException
-	*/
+	*	Extension to CommAPI.  Set Baud Base to 38600 on Linux and W32
+	*	before using.
+	*	@param BaudBase The clock frequency divided by 16.  Default
+	*	BaudBase is 115200.
+	*	@return true on success
+	*	@throws UnsupportedCommOperationException, IOException
+	**/
 
 	public boolean setBaudBase(int BaudBase)
 		throws UnsupportedCommOperationException,
 		IOException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:setBaudBase()");
+			System.out.println(  "RXTXPort:setBaudBase()");
 		return nativeSetBaudBase(BaudBase);
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  @return BaudBase
-	*  @throws UnsupportedCommOperationException, IOException
-	*/
+	*	Extension to CommAPI
+	*	@return BaudBase
+	*	@throws UnsupportedCommOperationException, IOException
+	**/
 
 	public int getBaudBase() throws UnsupportedCommOperationException,
 		IOException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:getBaudBase()");
+			System.out.println(  "RXTXPort:getBaudBase()");
 		return nativeGetBaudBase();
 	}
 
 	/**
-	*  Extension to CommAPI.  Set Baud Base to 38600 on Linux and W32
-	*  before using.
-	*  @param Divisor
-	*  @throws UnsupportedCommOperationException, IOException
-	*/
+	*	Extension to CommAPI.  Set Baud Base to 38600 on Linux and W32
+	*	before using.
+	*	@param Divisor
+	*	@throws UnsupportedCommOperationException, IOException
+	**/
 
 	public boolean setDivisor(int Divisor)
 		throws UnsupportedCommOperationException, IOException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:setDivisor()");
+			System.out.println(  "RXTXPort:setDivisor()");
 		return nativeSetDivisor(Divisor);
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  @return Divisor;
-	*  @throws UnsupportedCommOperationException, IOException
-	*/
+	*	Extension to CommAPI
+	*	@return Divisor;
+	*	@throws UnsupportedCommOperationException, IOException
+	**/
 
 	public int getDivisor() throws UnsupportedCommOperationException,
 		IOException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:getDivisor()");
+			System.out.println(  "RXTXPort:getDivisor()");
 		return nativeGetDivisor();
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  returns boolean true on success
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	returns boolean true on success
+	*	@throws UnsupportedCommOperationException
+	**/
 
 	public boolean setLowLatency() throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:setLowLatency()");
+			System.out.println(  "RXTXPort:setLowLatency()");
 		return nativeSetLowLatency();
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  returns boolean true on success
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	returns boolean true on success
+	*	@throws UnsupportedCommOperationException
+	**/
 
 	public boolean getLowLatency() throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:getLowLatency()");
+			System.out.println(  "RXTXPort:getLowLatency()");
 		return nativeGetLowLatency();
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  returns boolean true on success
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	returns boolean true on success
+	*	@throws UnsupportedCommOperationException
+	**/
 
 	public boolean setCallOutHangup(boolean NoHup)
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:setCallOutHangup()");
+			System.out.println(  "RXTXPort:setCallOutHangup()");
 		return nativeSetCallOutHangup(NoHup);
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  returns boolean true on success
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	returns boolean true on success
+	*	@throws UnsupportedCommOperationException
+	**/
 
 	public boolean getCallOutHangup()
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:getCallOutHangup()");
+			System.out.println(  "RXTXPort:getCallOutHangup()");
 		return nativeGetCallOutHangup();
 	}
 
 	/**
-	*  Extension to CommAPI
-	*  returns boolean true on success
-	*  @throws UnsupportedCommOperationException
-	*/
+	*	Extension to CommAPI
+	*	returns boolean true on success
+	*	@throws UnsupportedCommOperationException
+	**/
 
 	public boolean clearCommInput()
 		throws UnsupportedCommOperationException
 	{
 		if ( debug )
-			z.reportln(  "RXTXPort:clearCommInput()");
+			System.out.println(  "RXTXPort:clearCommInput()");
 		return nativeClearCommInput();
 	}
 
