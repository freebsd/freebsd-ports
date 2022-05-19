# Created by: Joe Marcus Clarke <marcus@FreeBSD.org>
#   $MCom: ports/trunk/audio/libcanberra-gtk3/Makefile 19814 2014-08-15 20:17:00Z gusi $

MASTERDIR=	${.CURDIR:H}/libcanberra
SLAVEPORT=	gtk2

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/canberra-gtk2
	@${MV} ${STAGEDIR}/${PREFIX}/include/canberra-gtk.h ${STAGEDIR}/${PREFIX}/include/canberra-gtk2

.include "${MASTERDIR}/Makefile"
