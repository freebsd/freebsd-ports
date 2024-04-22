PORTNAME=	svn2git
PORTVERSION=	1.0.18
PORTREVISION=	1
CATEGORIES=	devel kde

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Imports svn repositories into git
WWW=		http://gitorious.org/svn2git/svn2git

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libapr-1.so:devel/apr1
.if ${WITH_SUBVERSION_VER:U} == LTS
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion-lts
.else
LIB_DEPENDS+=	libsvn_client-1.so:devel/subversion
.endif
RUN_DEPENDS=	git:devel/git \
		p5-Term-ReadKey>=0:devel/p5-Term-ReadKey
.if ${WITH_SUBVERSION_VER:U} == LTS
RUN_DEPENDS+=	p5-subversion-lts>=0:devel/p5-subversion
.else
RUN_DEPENDS+=	p5-subversion>=0:devel/p5-subversion
.endif

USES=		compiler:c++11-lang qmake qt:5
USE_GITHUB=	yes
USE_QT=		core
GH_ACCOUNT=	svn-all-fast-export

OPTIONS_DEFINE=	FREEBSD_REPO
FREEBSD_REPO_DESC=	FreeBSD-repo only mode

QMAKE_ARGS=	SVN_INCLUDE=${LOCALBASE}/include/subversion-1 \
		SVN_LIBDIR=${LOCALBASE}/lib \
		APR_INCLUDE=${LOCALBASE}/include/apr-1
PLIST_FILES=	bin/svn2git

FREEBSD_REPO_EXTRA_PATCHES=	${PATCHDIR}/freebsd-export-patch

post-patch:
	@${REINPLACE_CMD} -e "s|/usr/local|${LOCALBASE}|"  \
		-e "s/VERSION = .*/VERSION = ${PORTVERSION}/" ${WRKSRC}/src/src.pro

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svn2git ${STAGEDIR}${PREFIX}/bin/

.include <bsd.port.mk>
