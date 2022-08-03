PORTNAME=	muon
PORTVERSION=	0.0.1.p1
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	https://git.sr.ht/~lattis/muon/archive/
DISTNAME=	b44e90f

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Build system compatible with meson

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

BUILD_DEPENDS=	scdoc:textproc/scdoc

USES=		ninja pkgconfig:both

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTNAME}
BUILD_WRKSRC=	${WRKSRC}/_build
INSTALL_WRKSRC=	${WRKSRC}/_build

ALL_TARGET=
PLIST_FILES=	bin/muon \
		share/man/man1/muon.1.gz \
		share/man/man5/meson.build.5.gz

post-patch:
# this confuses some of the FreeBSD configure targets
	@${RM} -r ${WRKSRC}/tests/project/common

do-configure:
	@(cd ${WRKSRC} && \
		${SH} bootstrap.sh && \
		./muon setup -Dlibcurl=disabled -Dlibarchive=disabled ${BUILD_WRKSRC})

do-install:
	@(${SETENV} ${MAKE_ENV} ${BUILD_WRKSRC}/muon -C ${BUILD_WRKSRC} install)

.include <bsd.port.mk>
