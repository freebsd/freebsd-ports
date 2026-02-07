MASTERDIR=	${.CURDIR:H}/libcanberra
PORTREVISION=	11
CANBERRA=	gtk3

post-install:
	@${MKDIR} ${STAGEDIR}/${PREFIX}/include/canberra-gtk3
	@${MV} ${STAGEDIR}/${PREFIX}/include/canberra-gtk.h ${STAGEDIR}/${PREFIX}/include/canberra-gtk3

.include "${MASTERDIR}/Makefile"
