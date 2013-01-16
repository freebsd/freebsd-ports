# Created by: David Naylor <naylor.b.david@gmail.com>
# $FreeBSD$

PORTNAME=	svn2git
DISTVERSION=	1.0.5
CATEGORIES=	devel kde
MASTER_SITES=	http://cloud.github.com/downloads/DragonSA/${PORTNAME}/

MAINTAINER=	dbn@FreeBSD.org
COMMENT=	Imports svn repositories into git

LICENSE=	GPLv3

LIB_DEPENDS=	svn_client-1:${PORTSDIR}/devel/subversion
RUN_DEPENDS+=	git:${PORTSDIR}/devel/git \
		p5-Term-ReadKey>=0:${PORTSDIR}/devel/p5-Term-ReadKey \
		p5-subversion>=0:${PORTSDIR}/devel/p5-subversion

USE_XZ=		yes
USE_QT4=	corelib qmake_build
MAKE_JOBS_SAFE=	yes

PLIST_FILES=	bin/svn2git

post-patch:
	${REINPLACE_CMD} "s|/usr/local|${LOCALBASE}|" ${WRKSRC}/src/src.pro

do-configure:
	(cd ${WRKSRC}; ${SETENV} ${CONFIGURE_ENV} ${QMAKE} ${QMAKEFLAGS} fast-export2.pro)

do-install:
	${INSTALL_PROGRAM} ${WRKSRC}/svn2git ${PREFIX}/bin/

.include <bsd.port.mk>
