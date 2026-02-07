PORTNAME=	svn2git
DISTVERSION=	1.0.20
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	uzsolt@FreeBSD.org
COMMENT=	Imports svn repositories into git
WWW=		https://github.com/svn-all-fast-export/svn2git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1
RUN_DEPENDS=	git:devel/git \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey

.if ${WITH_SUBVERSION_VER:U} == LTS
LIB_DEPENDS=	libsvn_client-1.so:devel/subversion-lts
RUN_DEPENDS=	p5-subversion-lts>=0:devel/p5-subversion
.else
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion
RUN_DEPENDS=	p5-subversion>=0:devel/p5-subversion
.endif

USES=		compiler:c++11-lang qmake qt:6
USE_GITHUB=	yes
GH_ACCOUNT=	svn-all-fast-export
USE_QT=		5compat base
QMAKE_ARGS=	APR_INCLUDE=${LOCALBASE}/include/apr-1 \
		SVN_INCLUDE=${LOCALBASE}/include/subversion-1 \
		SVN_LIBDIR=${LOCALBASE}/lib

PLIST_FILES=	bin/svn2git

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"  \
		-e "s/VERSION = .*/VERSION = ${DISTVERSION}/" ${WRKSRC}/src/src.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svn2git ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
