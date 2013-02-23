# Created by: David Yeske <dyeske@gmail.com>
# $FreeBSD$

PORTNAME=	evolvotron
PORTVERSION=	0.6.3
CATEGORIES=	graphics
MASTER_SITES=	SF

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Generative software that evolves images/textures/patterns

LICENSE=	GPLv2

LIB_DEPENDS=	boost_thread:${PORTSDIR}/devel/boost-libs

OPTIONS_DEFINE=	DOCS

WRKSRC=		${WRKDIR}/${PORTNAME}

USE_QT4=	corelib gui xml moc_build qmake_build
USE_PYTHON=	yes
HAS_CONFIGURE=	yes
CONFIGURE_ENV=	QTDIR="${QT_PREFIX}"
MAKE_JOBS_UNSAFE=	yes

MAN1=		evolvotron.1 evolvotron_mutate.1 evolvotron_render.1
PORTDOCS=	*
PLIST_FILES=	bin/evolvotron bin/evolvotron_mutate bin/evolvotron_render \
		lib/libevolvotron.a lib/libfunction.a

DESKTOP_ENTRIES="Evolvotron" "Interactive image generator" "" "${PORTNAME}" \
		"Graphics;2DGraphics;" true

.include <bsd.port.pre.mk>

.if ${CXX:T:M*clang*} || ${OSVERSION} >= 1000024
.for i in libevolvotron libfunction
CXXFLAGS+=	-include ${WRKSRC}/${i}/${i}_precompiled.h \
		-I${WRKSRC}/${i}
.endfor
.else
QMAKEFLAGS+=	CONFIG+=precompile_header
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|/bin/bash|/bin/sh|' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		'/^CONFIG/s|precompile_header|| ; \
		 /DEFINES/s|_LINUX|_BSD|' ${WRKSRC}/common.pro

post-configure:
	@(cd ${WRKSRC} && ${SETENV} ${MAKE_ENV} ${QMAKE} ${QMAKEFLAGS} \
		VERSION_NUMBER="${PORTVERSION}" main.pro)

do-install:
.for i in evolvotron evolvotron_mutate evolvotron_render
	(cd ${WRKSRC}/${i} && ${INSTALL_PROGRAM} ${i} ${PREFIX}/bin)
	(cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${i}.1 ${MANPREFIX}/man/man1)
.endfor
.for i in libevolvotron libfunction
	(cd ${WRKSRC}/${i} && ${INSTALL_DATA} ${i}.a ${PREFIX}/lib)
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
	(cd ${WRKSRC} && ${INSTALL_DATA} evolvotron.html ${DOCSDIR})
.endif

.include <bsd.port.post.mk>
