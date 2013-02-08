# Created by: Igor Pokrovsky <ip@doom.homeunix.org>
# $FreeBSD$

PORTNAME=	fracplanet
PORTVERSION=	0.4.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	An interactive generator of planets and terrain

BUILD_DEPENDS=	xsltproc:${PORTSDIR}/textproc/libxslt
LIB_DEPENDS=	boost_program_options:${PORTSDIR}/devel/boost-libs

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_GL=		glu
USE_QT4=	corelib gui opengl \
		moc_build qmake_build
QT_NONSTANDARD=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
CONFIGURE_ARGS=	-spec ${QMAKESPEC}
USE_GMAKE=	yes

MAN1=		${PORTNAME}.1
PORTDOCS=	${PORTNAME}.css ${PORTNAME}.htm
PLIST_FILES=	bin/${PORTNAME}

post-patch:
.for file in BUILD VERSION configure
	@${REINPLACE_CMD} -e \
		'/^#!/s|/.*bash|/bin/sh|g' ${WRKSRC}/${file}
.endfor

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/${PORTNAME} ${PREFIX}/bin
	${INSTALL_MAN} ${WRKSRC}/man/man1/${PORTNAME}.1 ${MAN1PREFIX}/man/man1
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for file in ${PORTDOCS}
	${INSTALL_DATA} ${WRKSRC}/${file} ${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
