Apply patch.

Patch attached with submission follows:

*** src/RXTXCommDriver.java.orig	Sun Jan 29 23:37:49 2006
--- src/RXTXCommDriver.java	Sun Nov  1 19:36:18 2009
***************
*** 588,597 ****
--- 588,601 ----
  					else if(osName.equals("FreeBSD")) //FIXME this is probably wrong
  					{
  						String[] Temp = {
  							"ttyd",    //general purpose serial ports
  							"cuaa",    //dialout serial ports
+ 							"ttyu",    //general purpose serial ports (uart)
+ 							"cuau",    //dialout serial ports (uart)
+ 							"ttyU",    //USB serial ports
+ 							"cuaU",    //USB dial in serial ports
  							"ttyA",    //Specialix SI/XIO dialin ports
  							"cuaA",    //Specialix SI/XIO dialout ports
  							"ttyD",    //Digiboard - 16 dialin ports
  							"cuaD",    //Digiboard - 16 dialout ports
  							"ttyE",    //Stallion EasyIO (stl) dialin ports


