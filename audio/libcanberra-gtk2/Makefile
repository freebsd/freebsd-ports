MASTERDIR=	${.CURDIR:H}/libcanberra
SLAVEPORT=	gtk2

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/canberra-gtk2
	@${MV} ${STAGEDIR}/${PREFIX}/include/canberra-gtk.h ${STAGEDIR}/${PREFIX}/include/canberra-gtk2

.include "${MASTERDIR}/Makefile"
