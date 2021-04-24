#!/bin/sh -ex

##########################################################################
#   Function description:
#       Pause until user presses return
##########################################################################

pause()
{
    local junk
    
    printf "Press return to continue..."
    read junk
}

esearch -db pubmed -query "opsin gene conversion" | \
  elink -related | \
  elink -target protein
pause

esearch -db pubmed -query "lycopene cyclase" | efetch -format abstract
pause

esearch -db protein -query "lycopene cyclase" | efetch -format fasta
pause

esearch -db pubmed -query "opsin gene conversion" | \
  elink -related | efilter -query "tetrachromacy"
pause

efilter -days 60 -datetype PDAT
efilter -mindate 1990 -maxdate 1999 -datetype PDAT

