#   $MCom: ports/trunk/audio/libcanberra-gtk3/Makefile 19814 2014-08-15 20:17:00Z gusi $

MASTERDIR=	${.CURDIR:H}/libcanberra
SLAVEPORT=	gtk3

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/canberra-gtk3
	@${MV} ${STAGEDIR}/${PREFIX}/include/canberra-gtk.h ${STAGEDIR}/${PREFIX}/include/canberra-gtk3

.include "${MASTERDIR}/Makefile"
