#!/bin/sh

# if called with an extra argument, assume it's "BATCH"
if [ $# = 1 ]; then
  BATCH=yes
fi

PRINTER_DEVS=
DONE=no
while [ "$DONE" != "yes" ];
do 
	if [ "$BATCH" = "yes" ]; then
		CHOICE=19
	else
		echo "Select printers."
  		echo "Separate multiple entries with white spaces."
		echo "1.  Canon BJ-10V"
		echo "2.  Canon BJC-600J"
		echo "3.  HP DeskJet 500C"
		echo "4.  HP DeskJet 550C"
		echo "5.  HP DeskJet 505J"
		echo "6.  generic dot impact printer"
		echo "7.  Epson LP-1700, LP-8200 (ESC/PS 300/600 dpi)"
		echo "8.  ESC/Page 300dpi generic"
		echo "9.  Star JJ-100"
		echo "10. LIPS III generic"
		echo "11. LIPS IV , IVc generic"
		echo "12.  MAG format"
		echo "13. MJC720, 800, 900, 5000 (ESC/P at 180/360/720 dpi)"
		echo "14. MJ-500C"
		echo "15. NEC PC-PR150"
		echo "16. NEC PC-PR201"
		echo "17. NEC PC-PR1000 /4"
 		echo "18. fax g3"
 		echo "19. All"
 		echo "20. Done"
		echo -n "> "
		read CHOICE
		echo $CHOICE
	fi
	for i in $CHOICE; do
		case $i in
		1)
			PRINTER_DEVS="$PRINTER_DEVS bj10v.dev bj10vh.dev"
			echo "Added Canon BJ-10V."
		;;
		2)
			PRINTER_DEVS="$PRINTER_DEVS bjc600j.dev bjc600jc.dev"
			echo "Added Canon BJC-600J."
		;;
		3)
			PRINTER_DEVS="$PRINTER_DEVS cdj500.dev"
			echo "Added HP DeskJet 500C."
		;;
		4)
			PRINTER_DEVS="$PRINTER_DEVS cdj550.dev"
			echo "Added HP DeskJet 550C."
		;;
		5)
			PRINTER_DEVS="$PRINTER_DEVS dj505j.dev dj505jc.dev"
			echo "Added HP DeskJet 505J."
		;;
		6)
			PRINTER_DEVS="$PRINTER_DEVS dmprt.dev"
			echo "Added generic dot impact printer."
		;;
		7)
			PRINTER_DEVS="$PRINTER_DEVS epag300.dev epag600.dev"
			echo "Added Epson LP-8200 (ESC/Page 300/600 dpi)."
		;;
		8)
			PRINTER_DEVS="$PRINTER_DEVS epag.dev"
			echo "Added ESC/Page 300dpi generic."
		;;
		9)
			PRINTER_DEVS="$PRINTER_DEVS jj100.dev"
			echo "Added Star JJ-100."
		;;
		10)
			PRINTER_DEVS="$PRINTER_DEVS lips3.dev"
			echo "Added LIPS III generic."
		;;
		11)
			PRINTER_DEVS="$PRINTER_DEVS lips4.dev lips4c.dev"
			echo "Added LIPS IV, IVc generic."
		;;
		12)
			PRINTER_DEVS="$PRINTER_DEVS mag16.dev mag256.dev"
			echo "Added MAG format."
		;;
		13)
			PRINTER_DEVS="$PRINTER_DEVS mjc180.dev mjc360.dev mjc720.dev"
			echo "Added MJC720, 800, 900, 5000 (ESC/P at 180/360/720 dpi)."
		;;
		14)
			PRINTER_DEVS="$PRINTER_DEVS mj500c.dev"
			echo "Added MJ-500C."
		;;
		15)
			PRINTER_DEVS="$PRINTER_DEVS pr150.dev"
			echo "Added NEC PC-PR150."
		;;
		16)
			PRINTER_DEVS="$PRINTER_DEVS pr201.dev"
			echo "Added NEC PC-PR201."
		;;
		17)
			PRINTER_DEVS="$PRINTER_DEVS pr1000.dev pr1000_4.dev"
			echo "Added NEC PC-PR1000 /4."
		;;
		18)
			PRINTER_DEVS="$PRINTER_DEVS tiffg3.dev"
			echo "Added G3 FAX."
		;;
 		19)
			PRINTER_DEVS='bj10v.dev bj10vh.dev bjc600j.dev bjc600jc.dev cdj500.dev cdj550.dev dj505j.dev dj505jc.dev dmprt.dev epag300.dev epag600.dev epag.dev jj100.dev lips3.dev lips4.dev lips4c.dev mag16.dev mag256.dev mjc180.dev mjc360.dev mjc720.dev mj500c.dev pr150.dev pr201.dev pr1000_4.dev pr1000.dev tiffg3.dev'
			echo "All."
			DONE=yes
		;;
		20)
			echo "Done."
			DONE=yes
		;;
		*)
			PRINTER_DEVS='bj10v.dev bj10vh.dev bjc600j.dev bjc600jc.dev cdj500.dev cdj550.dev dj505j.dev dj505jc.dev dmprt.dev epag300.dev epag600.dev epag.dev jj100.dev lips3.dev lips4.dev lips4c.dev mag16.dev mag256.dev mjc180.dev mjc360.dev mjc720.dev mj500c.dev pr150.dev pr201.dev pr1000_4.dev pr1000.dev tiffg3.dev'
			echo "All."
			DONE=yes
		;;
		esac
	done
done


mv Makefile Makefile.org
sed -e "s/DEVICE_DEVS=x11.dev/DEVICE_DEVS=x11.dev $PRINTER_DEVS/" Makefile.org >Makefile
