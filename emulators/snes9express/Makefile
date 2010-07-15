# New ports collection makefile for:	snes9express
# Date created:			15 Mar 2004
# Whom:				Travis Poppe <tlp@liquidx.org>
#
# $FreeBSD$
#

PORTNAME=	snes9express
PORTVERSION=	1.43
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface for snes9x

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USE_GNOME=	gtk20
USE_GETTEXT=	yes
GNU_CONFIGURE=	yes
MAKE_JOBS_SAFE=	yes

PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/snes.s9xskin \
		%%DATADIR%%/snsp.s9xskin
PLIST_DIRS=	%%DATADIR%%

post-patch:
	@${REINPLACE_CMD} -e 's|<endian\.h>|<sys/endian.h>|' \
		${WRKSRC}/s9xskin.cc

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	@${MKDIR} ${DATADIR}
	${INSTALL_DATA} ${WRKSRC}/*.s9xskin ${DATADIR}
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
