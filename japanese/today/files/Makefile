#
# Makefile for today
#
# $FreeBSD$

CC ?= cc
CFLAGS += -DTRANS -DMSG_STYLE -DINTERNAL_KYUREKI_TBL -D_T_SEARCH_CMDPATH=\"${PREFIX}/etc\" #-DUSE_TERMCAP
LDLIBS = -lm #-ltermcap

HFILES = cdefs.h chu68k.h cmsdos.h cunix.h cwin32.h extern.h
        
OBJST1 = birthday.o config.o date.o event.o getfile.o \
  getsb.o history.o kansi.o kyureki.o \
  kyusei.o list.o machine.o main.o misc.o
OBJST2 = pager.o rdcalend.o rekichu.o schedule.o sekki.o \
  sepparam.o
OBJS_TDY = $(OBJST1) $(OBJST2) version.o
OBJSC1 = config.o getfile.o getsb.o kyureki2.o \
  misc2.o rdcalend.o schedule2.o
OBJS_CAL = calendar.o $(OBJSC1)


all: today calendar dayinfo

install: today calendar dayinfo
	${BSD_INSTALL_PROGRAM} today ${PREFIX}/bin/today
	${BSD_INSTALL_PROGRAM} calendar ${PREFIX}/bin/calendar-today
	${BSD_INSTALL_PROGRAM} dayinfo ${PREFIX}/bin/dayinfo
	${BSD_INSTALL_DATA} today.cnf ${PREFIX}/etc
	mkdir -p ${PREFIX}/share/today
	${BSD_INSTALL_DATA} *.tbl ${PREFIX}/share/today
	mkdir -p ${PREFIX}/share/doc/ja/today
	${BSD_INSTALL_DATA} today.doc ${PREFIX}/share/doc/ja/today

calendar: $(OBJS_CAL)
	$(CC) $(OBJS_CAL) $(LDLIBS) -o $@
       
today: $(OBJS_TDY)
	$(CC) $(OBJS_TDY) $(LDLIBS) -o $@

dayinfo: dayinfo.c
	$(CC) $(CFLAGS) $(LDLIBS) $? -o $@

clean:
	rm -f *.o core dayinfo calendar today


birthday.o: birthday.c $(HFILES)
calendar.o: calendar.c $(HFILES) $(OBJSC1)
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ calendar.c

config.o: config.c $(HFILES)
date.o: date.c $(HFILES)
event.o: event.c $(HFILES)
getfile.o: getfile.c $(HFILES)
getopt.o: getopt.c $(HFILES)
getsb.o: getsb.c $(HFILES)
history.o: history.c $(HFILES)
kansi.o: kansi.c $(HFILES)
kyureki.o: kyureki.c $(HFILES) kyutbl.c
kyureki2.o: kyureki.c $(HFILES) kyutbl.c
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ kyureki.c

kyusei.o: kyusei.c $(HFILES)
list.o: list.c $(HFILES)
machine.o: machine.c $(HFILES)
main.o: main.c $(HFILES)
misc.o: misc.c $(HFILES)
misc2.o: misc.c $(HFILES)
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ misc.c

pager.o: pager.c $(HFILES)
rdcalend.o: rdcalend.c $(HFILES)
rekichu.o: rekichu.c $(HFILES)
schedule.o: schedule.c $(HFILES)
schedule2.o: schedule.c $(HFILES)
	$(CC) $(CFLAGS) -DINCLUDE_CALENDAR -c -o $@ schedule.c

sekki.o: sekki.c $(HFILES)
sepparam.o: sepparam.c $(HFILES)
version.o: version.c $(HFILES) $(OBJST1) $(OBJST2)
