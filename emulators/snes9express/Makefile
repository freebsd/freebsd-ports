# Created by: Travis Poppe <tlp@liquidx.org>
# $FreeBSD$

PORTNAME=	snes9express
PORTVERSION=	1.43
PORTREVISION=	1
CATEGORIES=	emulators
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	GTK interface for snes9x

RUN_DEPENDS=	snes9x:${PORTSDIR}/emulators/snes9x

USE_GNOME=	gtk20
USES=		gettext
GNU_CONFIGURE=	yes

BROKEN=		does not build

PORTDOCS=	AUTHORS ChangeLog NEWS README
PLIST_FILES=	bin/${PORTNAME} \
		%%DATADIR%%/snes.s9xskin \
		%%DATADIR%%/snsp.s9xskin
PLIST_DIRS=	%%DATADIR%%

NO_STAGE=	yes
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

.include <bsd.port.pre.mk>

.if ${ARCH} == "sparc64"
BROKEN=		Does not compile on sparc64
.endif

.include <bsd.port.post.mk>
