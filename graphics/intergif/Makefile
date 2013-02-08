# Created by: jamie
# $FreeBSD$

PORTNAME=	interGif
PORTVERSION=	6.15
CATEGORIES=	graphics
MASTER_SITES=	http://utter.chaos.org.uk/~pdh/software/arc/
DISTNAME=	ig${PORTVERSION:S,.,,}src
EXTRACT_SUFX=	.tgz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Efficient animated GIF optimiser

WRKSRC=		${WRKDIR}/igsrc

MAKEFILE=	makefile.ix
ALL_TARGET=	intergif
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/intergif

post-patch:
	@${REINPLACE_CMD} -e \
		's|=.*cc|= $$(CC)| ; \
		 s|-O6|$$(CFLAGS)| ; \
		 s|@echo|@true| ; \
		 s|@$$(cc)|$$(cc)|' ${WRKSRC}/src/makefile.ix

do-install:
	(cd ${WRKSRC} && ${INSTALL_PROGRAM} intergif ${PREFIX}/bin)

.include <bsd.port.mk>
