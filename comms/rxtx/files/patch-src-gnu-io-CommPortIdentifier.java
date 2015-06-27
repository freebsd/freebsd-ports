--- src/gnu/io/CommPortIdentifier.java.orig	2008-11-27 20:02:34.000000000 +0000
+++ src/gnu/io/CommPortIdentifier.java	2015-05-11 16:51:34.000000000 +0100
@@ -76,85 +76,138 @@
 	public static final int PORT_RS485    = 4;  // rs485 Port
 	public static final int PORT_RAW      = 5;  // Raw Port
 	private String PortName;
-	private boolean Available = true;    
+	private static boolean init_clean = false;
+	private boolean Available = true;
 	private String Owner;    
 	private CommPort commport;
 	private CommDriver RXTXDriver;
  	static CommPortIdentifier   CommPortIndex;
 	CommPortIdentifier next;
 	private int PortType;
-	private final static boolean debug = false;
+	private final static boolean debug = "true".equals( System.getProperty( "gnu.io.rxtx.DEBUG" ) );
 	static Object Sync;
 	Vector ownershipListener;
 
 
 
-/*------------------------------------------------------------------------------
-	static {}   aka initialization
-	accept:       -
-	perform:      load the rxtx driver
-	return:       -
-	exceptions:   Throwable
-	comments:     static block to initialize the class
-------------------------------------------------------------------------------*/
-	// initialization only done once....
+	/**
+	*	static {}   aka initialization
+	*	accept:       -
+	*	perform:      load the rxtx driver
+	*	return:       -
+	*	exceptions:   Throwable
+	*	comments:     static block to initialize the class
+	* 	
+	* 	initialization only done once....
+	* 	
+	**/
+	
 	static 
 	{
-		if(debug) System.out.println("CommPortIdentifier:static initialization()");
+		if(debug) System.out.println("CommPortIdentifier:Static()");
+		
 		Sync = new Object();
 		try 
 		{
+			if(debug) System.out.println(" Pre RXTXDriver.Loading New Class (Clean)");
+			
+			init_clean = true;
+			
 			CommDriver RXTXDriver = (CommDriver) Class.forName("gnu.io.RXTXCommDriver").newInstance();
+			
+			if(debug) System.out.println(" Pre RXTXDriver.initialize()");
+			
 			RXTXDriver.initialize();
+			
+			if(debug) System.out.println(" Post RXTXDriver.initialize()");
+			
 		} 
 		catch (Throwable e) 
 		{
-			System.err.println(e + " thrown while loading " + "gnu.io.RXTXCommDriver");
+			
+			if(debug) System.out.println(" " + e + " thrown while loading gnu.io.RXTXCommDriver");
+			
+			System.err.println(e + " thrown while loading gnu.io.RXTXCommDriver");
+			
+			init_clean = false;
+			
 		}
 
 		String OS;
 
 		OS = System.getProperty("os.name");
+		
+		if(debug) System.out.println(" The OS is " + OS);
+		
 		if(OS.toLowerCase().indexOf("linux") == -1)
 		{
-			if (debug)
-				System.out.println("Have not implemented native_psmisc_report_owner(PortName)); in CommPortIdentifier");
+			if (debug) 
+			{
+				System.out.println(" WARNING:");
+				System.out.println(" native_psmisc_System.out.println_owner(@)) not implemented");
+				
+				/**
+				*	Not Implemented:
+				* 	
+				*	native_psmisc_System.out.println_owner(PortName)
+				* 	in CommPortIdentifier")
+				**/
+				
+			}
 		}
+		
+		if(debug) System.out.println(" Loading Library...");
+		
 		System.loadLibrary( "rxtxSerial" );
-	}
-	CommPortIdentifier ( String pn, CommPort cp, int pt, CommDriver driver) 
+		
+		if(debug) System.out.println(" init_clean is " + init_clean);
+		if(debug) System.out.println("CommPortIdentifier:Static:Exit");
+		
+	}
+	CommPortIdentifier 
+	(
+		String pn,
+		CommPort cp,
+		int pt,
+		CommDriver driver
+	) 
 	{
 		PortName        = pn;
 		commport        = cp;
 		PortType        = pt;
 		next            = null;
 		RXTXDriver      = driver;
-
 	}
 
-/*------------------------------------------------------------------------------
-	addPortName()
-	accept:         Name of the port s, Port type, 
-                        reverence to RXTXCommDriver.
-	perform:        place a new CommPortIdentifier in the linked list
-	return: 	none.
-	exceptions:     none.
-	comments:
-------------------------------------------------------------------------------*/
+	/**
+	*	addPortName()
+	*	accept:		Name of the port s, Port type,
+	*				reference to RXTXCommDriver.
+	*	perform:	place a new CommPortIdentifier in the linked list
+	*	return:		none.
+	*	exceptions:	none.
+	*	comments:
+	**/
+	
 	public static void addPortName(String s, int type, CommDriver c) 
 	{ 
 
-		if(debug) System.out.println("CommPortIdentifier:addPortName("+s+")");
+		if(debug) System.out.println("CommPortIdentifier:addPortName(" + s + ")");
+		
 		AddIdentifierToList(new CommPortIdentifier(s, null, type, c));
+		
+		if(debug) System.out.println("CommPortIdentifier:addPortName:Exit");
 	}
-/*------------------------------------------------------------------------------
-	AddIdentifierToList()
-	accept:        The cpi to add to the list. 
-	perform:        
-	return: 	
-	exceptions:    
-	comments:
-------------------------------------------------------------------------------*/
+	
+	/**
+	*	AddIdentifierToList()
+	*	accept:		The cpi to add to the list. 
+	*	perform:        
+	*	return: 	
+	*	exceptions:    
+	*	comments:
+	**/
+	
 	private static void AddIdentifierToList( CommPortIdentifier cpi)
 	{
 		if(debug) System.out.println("CommPortIdentifier:AddIdentifierToList()");
@@ -163,7 +216,7 @@
 			if (CommPortIndex == null) 
 			{
 				CommPortIndex = cpi;
-				if(debug) System.out.println("CommPortIdentifier:AddIdentifierToList() null");
+				if(debug) System.out.println(" Com Port Index is null!");
 			}
 			else
 			{ 
@@ -171,264 +224,351 @@
 				while (index.next != null)
 				{
 					index = index.next;
-					if(debug) System.out.println("CommPortIdentifier:AddIdentifierToList() index.next");
 				}
 				index.next = cpi;
 			} 
 		}
+		
+		if(debug) System.out.println("CommPortIdentifier:addIdentifier:Exit");
+		
 	}
-/*------------------------------------------------------------------------------
-	addPortOwnershipListener()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:   
-------------------------------------------------------------------------------*/
+	
 	public void addPortOwnershipListener(CommPortOwnershipListener c) 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:addPortOwnershipListener()");
 
-		/*  is the Vector instantiated? */
+		/**
+		*	is the Vector instantiated?
+		**/
 
 		if( ownershipListener == null )
 		{
 			ownershipListener = new Vector();
 		}
 
-		/* is the ownership listener already in the list? */
+		/**
+		*	is the ownership listener already in the list?
+		**/
 
 		if ( ownershipListener.contains(c) == false)
 		{
 			ownershipListener.addElement(c);
 		}
+		
+		if(debug) System.out.println("CommPortIdentifier:addPortOwnershipListener:Exit");
 	}
-/*------------------------------------------------------------------------------
-	getCurrentOwner()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:    
-------------------------------------------------------------------------------*/
+
 	public String getCurrentOwner() 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:getCurrentOwner()");
+		
 		return( Owner );
+		
 	}
-/*------------------------------------------------------------------------------
-	getName()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+	
 	public String getName() 
 	{ 
-		if(debug) System.out.println("CommPortIdentifier:getName()");
+		if(debug) System.out.println("CommPortIdentifier:getName(" + PortName + ")");
+		
 		return( PortName );
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	getPortIdentifier()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:   
-------------------------------------------------------------------------------*/
+	
 	static public CommPortIdentifier getPortIdentifier(String s) throws NoSuchPortException 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:getPortIdentifier(" + s +")");
+		
 		CommPortIdentifier index;
 
 		synchronized (Sync) 
 		{
 		 	index = CommPortIndex;
-			while (index != null && !index.PortName.equals(s)) { 
+		 	
+			while (index != null && !index.PortName.equals(s))
+			{ 
 				index = index.next;
 			}
+			
 			if (index == null) {
-				/* This may slow things down but if you pass the string for the port after
-				   a device is plugged in, you can find it now.
-
-				   http://bugzilla.qbang.org/show_bug.cgi?id=48
-				*/
+				
+				/**
+				*	This may slow things down but if you pass the string for the port after
+				*	a device is plugged in, you can find it now.
+				*	
+				*	http://bugzilla.qbang.org/show_bug.cgi?id=48
+				**/
+				
 				getPortIdentifiers();
+				
 			 	index = CommPortIndex;
-				while (index != null && !index.PortName.equals(s)) { 
+			 	
+				while (index != null && !index.PortName.equals(s))
+				{ 
 					index = index.next;
 				}
+				
 			}
+			
 		}
+		
 		if (index != null) return index;
 		else
 		{
-			if ( debug )
-				System.out.println("not found!" + s);
+			if (debug) System.out.println(" not found!" + s);
+			
 			throw new NoSuchPortException();
 		}
+		
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	getPortIdentifier()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:    
-------------------------------------------------------------------------------*/
+		
 	static public CommPortIdentifier getPortIdentifier(CommPort p) 
 		throws NoSuchPortException 	
 	{ 
-		if(debug) System.out.println("CommPortIdentifier:getPortIdentifier(CommPort)");
+		if(debug) System.out.println("CommPortIdentifier:getPortIdentifier(" + p + ")");
+		
 		CommPortIdentifier c;
+		
 		synchronized( Sync )
 		{
+			
 			c = CommPortIndex;
-			while ( c != null && c.commport != p )
+			
+			while
+			(
+				c != null &&
+				c.commport != p
+			)
+			{
 				c = c.next;
+			}
 		}
+		
 		if ( c != null )
 			return (c);
 
-		if ( debug )
-			System.out.println("not found!" + p.getName());
+		if ( debug ) System.out.println(" not found!" + p.getName());
+		
 		throw new NoSuchPortException();
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	getPortIdentifiers()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+	
 	static public Enumeration getPortIdentifiers() 
 	{ 
-		if(debug) System.out.println("static CommPortIdentifier:getPortIdentifiers()");
-		//Do not allow anybody get any ports while we are re-initializing
-		//because the CommPortIndex points to invalid instances during that time
+		if(debug) System.out.println("CommPortIdentifier:getPortIdentifiers()");
+		
+		/** 
+		*	Do not allow anybody get any ports while we are re-initializing
+		*	because the CommPortIndex points to invalid instances during that time
+		*/
+		
 		synchronized(Sync) {
-			//Remember old ports in order to restore them for ownership events later
+			
+			/**
+			*	Remember old ports in order to restore them for ownership events later
+			**/
+			if(debug) System.out.println(" backing up current ports");
 			HashMap oldPorts = new HashMap();
 			CommPortIdentifier p = CommPortIndex;
-			while(p!=null) {
+			
+			while(p!=null) 
+			{
 				oldPorts.put(p.PortName, p);
 				p = p.next;
 			}
+			
 			CommPortIndex = null;
+			
 			try 
 			{
-				//Initialize RXTX: This leads to detecting all ports
-				//and writing them into our CommPortIndex through our method
-				//{@link #addPortName(java.lang.String, int, gnu.io.CommDriver)}
-				//This works while lock on Sync is held
-				CommDriver RXTXDriver = (CommDriver) Class.forName("gnu.io.RXTXCommDriver").newInstance();
-				RXTXDriver.initialize();
-				//Restore old CommPortIdentifier objects where possible, 
-				//in order to support proper ownership event handling.
-				//Clients might still have references to old identifiers!
+				/**
+				*	Initialize RXTX: This leads to detecting all ports
+				*	and writing them into our CommPortIndex through our method
+				*	{@link #addPortName(java.lang.String, int, gnu.io.CommDriver)}
+				*	This works while lock on Sync is held
+				**/
+				
+				/**
+				*	However, if RXTX is being called invoked by 
+				* 	CommPortIdentifier:getPortIdentifiers for the first
+				* 	time, they have just been enumerated by static() in 
+				*	this class, so we don't need to repeat on the first
+				* 	time.
+				**/
+				
+				if ( init_clean == false )
+				{
+					if(debug) System.out.println(" RXTX init() is dirty");
+					if(debug) System.out.println(" Creating RXTX new instance");
+					CommDriver RXTXDriver = (CommDriver) Class.forName("gnu.io.RXTXCommDriver").newInstance();
+					if(debug) System.out.println(" Creating RXTX new instance");
+					RXTXDriver.initialize();
+					
+				}
+				else
+				{
+					if(debug) System.out.println(" RXTX init() still clean, now marking as dirty");
+					init_clean = false;
+				}
+				
+				/**
+				*	Restore old CommPortIdentifier objects where possible, 
+				*	in order to support proper ownership event handling.
+				*	Clients might still have references to old identifiers!
+				**/
+				
 				CommPortIdentifier curPort = CommPortIndex;
 				CommPortIdentifier prevPort = null;
-				while(curPort!=null) {
+				while(curPort!=null)
+				{
 					CommPortIdentifier matchingOldPort = (CommPortIdentifier)oldPorts.get(curPort.PortName);
-					if(matchingOldPort!=null && matchingOldPort.PortType == curPort.PortType) {
-						//replace new port by old one
+					if
+					(
+						matchingOldPort!=null && 
+						matchingOldPort.PortType == curPort.PortType
+					)
+					{
+						/**
+						*	replace new port by old one
+						**/
+						
 						matchingOldPort.RXTXDriver = curPort.RXTXDriver;
 						matchingOldPort.next = curPort.next;
-						if(prevPort==null) {
+						
+						if (prevPort==null)
+						{
 							CommPortIndex = matchingOldPort;
-						} else {
+						}
+						else
+						{
 							prevPort.next = matchingOldPort;
 						}
 						prevPort = matchingOldPort;
-					} else {
+					}
+					else
+					{
 						prevPort = curPort;
 					}
+					
 					curPort = curPort.next;
+					
 				}
+				
 			} 
 			catch (Throwable e) 
 			{
+				
+				System.out.println(" " + e + " thrown while loading gnu.io.RXTXCommDriver");
+				
 				System.err.println(e + " thrown while loading " + "gnu.io.RXTXCommDriver");
+				
 				System.err.flush();
+				
 			}
 		}
+		
+		if(debug) System.out.println("CommPortIdentifier:getPortIdentifiers:Exit");
+		
 		return new CommPortEnumerator();
+		
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	getPortType()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+	
 	public int getPortType() 
 	{ 
-		if(debug) System.out.println("CommPortIdentifier:getPortType()");
+		if(debug) System.out.println("CommPortIdentifier:getPortType(" + PortType + ")");
+		
 		return( PortType );
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	isCurrentlyOwned()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:    
-------------------------------------------------------------------------------*/
+		
 	public synchronized boolean isCurrentlyOwned() 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:isCurrentlyOwned()");
+		
 		return(!Available);
+		
+		
 	}
-/*------------------------------------------------------------------------------
-	open()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+		
 	public synchronized CommPort open(FileDescriptor f) throws UnsupportedCommOperationException 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:open(FileDescriptor)");
+		
 		throw new UnsupportedCommOperationException();
+		
 	}
 	private native String native_psmisc_report_owner(String PortName);
 
-/*------------------------------------------------------------------------------
-	open()
-	accept:      application making the call and milliseconds to block
-                     during open.
-	perform:     open the port if possible
-	return:      CommPort if successful
-	exceptions:  PortInUseException if in use.
-	comments:
-------------------------------------------------------------------------------*/
+	/**
+	*	open()
+	*	accept:		application making the call and milliseconds to block
+    *				during open.
+	*	perform:	open the port if possible
+	*	return:		CommPort if successful
+	*	exceptions:	PortInUseException if in use.
+	*	comments:	
+	**/
+	
 	private boolean HideOwnerEvents;
 
-	public CommPort open(String TheOwner, int i) 
-		throws gnu.io.PortInUseException 
+	public CommPort open(
+		String TheOwner, 
+		int i
+	) 
+	throws gnu.io.PortInUseException 
 	{ 
-		if(debug) System.out.println("CommPortIdentifier:open("+TheOwner + ", " +i+")");
+		if(debug) System.out.println("CommPortIdentifier:open(" + TheOwner + ", " + i + ")");
+		
 		boolean isAvailable;
-		synchronized(this) {
+		
+		synchronized(this)
+		{
 			isAvailable = this.Available;
+			
 			if (isAvailable) {
-			    //assume ownership inside the synchronized block
+				
+				/**
+				*	assume ownership inside the synchronized block
+				*	? Of you and me !
+				**/
+				
 			    this.Available = false;
 			    this.Owner = TheOwner;
 			}
 		}
+		
 		if (!isAvailable)
 		{
 			long waitTimeEnd = System.currentTimeMillis() + i;
-			//fire the ownership event outside the synchronized block
-			fireOwnershipEvent(CommPortOwnershipListener.PORT_OWNERSHIP_REQUESTED);
+			
+			/**
+			*	Fire the ownership event outside the synchronized block
+			**/
+			
+			fireOwnershipEvent
+			(
+				CommPortOwnershipListener.PORT_OWNERSHIP_REQUESTED
+			);
+			
 			long waitTimeCurr;
-			synchronized(this) {
-				while(!Available && (waitTimeCurr=System.currentTimeMillis()) < waitTimeEnd) {
+			
+			synchronized(this)
+			{
+				
+				while
+				(
+					!Available && 
+					(
+						waitTimeCurr=System.currentTimeMillis()
+					) < waitTimeEnd
+				) 
+				{
 					try
 					{
 						wait(waitTimeEnd - waitTimeCurr);
@@ -439,91 +579,134 @@
 						break;
 					}
 				}
+				
 				isAvailable = this.Available;
+				
 				if (isAvailable) {
-					//assume ownership inside the synchronized block
+					/**
+					*	Assume ownership inside the synchronized block
+					* 	? of you an me !
+					**/
 					this.Available = false;
 					this.Owner = TheOwner;
 				}
 			}
 		}
+		
 		if (!isAvailable)
 		{
 			throw new gnu.io.PortInUseException(getCurrentOwner());
 		}
-		//At this point, the CommPortIdentifier is owned by us.
-		try {
+		
+		/**
+		*	At this point, the CommPortIdentifier is owned by us.
+		**/
+		
+		try
+		{
 			if(commport == null)
 			{
-				commport = RXTXDriver.getCommPort(PortName,PortType);
+				commport = RXTXDriver.getCommPort(
+					PortName,
+					PortType
+				);
 			}
+			
 			if(commport != null)
 			{
-				fireOwnershipEvent(CommPortOwnershipListener.PORT_OWNED);
+				fireOwnershipEvent(
+					CommPortOwnershipListener.PORT_OWNED
+				);
+				
 				return commport;
 			}
 			else
 			{
-				throw new gnu.io.PortInUseException(
-						native_psmisc_report_owner(PortName));
+				throw new gnu.io.PortInUseException
+				(
+					native_psmisc_report_owner(PortName)
+				);
 			}
-		} finally {
+		}
+		finally 
+		{
 			if(commport == null) {
-				//something went wrong reserving the commport -> unown the port
+				
+				/**
+				*	something went wrong reserving the commport
+				*	-> release ownership (internal) of the port
+				**/
+				
 				synchronized(this) {
+					
 					this.Available = true;
 					this.Owner = null;
+					
 				}
 			}
+			if(debug) System.out.println("CommPortIdentifier:open:Exit");
 		}
-	}
-/*------------------------------------------------------------------------------
-	removePortOwnership()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+		
+		
+		
+	}	
+	
 	public void removePortOwnershipListener(CommPortOwnershipListener c) 
 	{ 
 		if(debug) System.out.println("CommPortIdentifier:removePortOwnershipListener()");
-		/* why is this called twice? */
-		if(ownershipListener != null)
+		
+		/**
+		*	why is this called twice?
+		**/
+		
+		if(ownershipListener != null) 
+		{
+			if(debug) System.out.println(" I was owned!");
 			ownershipListener.removeElement(c);
+		}
+		
+		if(debug) System.out.println("CommPortIdentifier:removePortOwnershipListener()");
 	}
 
-/*------------------------------------------------------------------------------
-	internalClosePort()
-	accept:       None
-	perform:      clean up the Ownership information and send the event
-	return:       None
-	exceptions:   None
-	comments:     None
-------------------------------------------------------------------------------*/
+	/**
+	*	internalClosePort()
+	*	accept:		None
+	*	perform:	clean up the Ownership information and send the event
+	*	return:		
+	*	exceptions:	
+	*	comments:	
+	**/
+	
 	void internalClosePort() 
 	{
+		
+		if(debug) System.out.println("CommPortIdentifier:internalClosePort()");
+		
 		synchronized(this) {
-			if(debug) System.out.println("CommPortIdentifier:internalClosePort()");
+			
 			Owner = null;
 			Available = true;
 			commport = null;
-			/*  this tosses null pointer?? */
+			
+			/**
+			*	this tosses null pointer??
+			**/
+			if(debug) System.out.println(" Notifying all...");
+			
 			notifyAll();
+			
 		}
+		
 		fireOwnershipEvent(CommPortOwnershipListener.PORT_UNOWNED);
+		
+		if(debug) System.out.println("CommPortIdentifier:internalClosePort:Exit");
 	}
-/*------------------------------------------------------------------------------
-	fireOwnershipEvent()
-	accept:
-	perform:
-	return:
-	exceptions:
-	comments:
-------------------------------------------------------------------------------*/
+	
 	void fireOwnershipEvent(int eventType)
 	{
+		
 		if(debug) System.out.println("CommPortIdentifier:fireOwnershipEvent( " + eventType + " )");
+		
 		if (ownershipListener != null)
 		{
 			CommPortOwnershipListener c;
@@ -532,6 +715,10 @@
 				c.ownershipChange(eventType))
 				c = (CommPortOwnershipListener) e.nextElement();
 		}
+		
+		if(debug) System.out.println("CommPortIdentifier:fireOwnershipEvent:Exit");
 	}
+	
+	
 }
 
