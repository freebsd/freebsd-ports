# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
#
# $FreeBSD$
#

PORTNAME=	omniORB
PORTVERSION=	4.0.0
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	ejc@FreeBSD.org

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
USE_PYTHON=	yes
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
INSTALLS_SHLIB=	yes
NO_FILTER_SHLIBS=	yes
MAKEFILE=	GNUmakefile
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPP=${CPP} PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=/usr \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-omniNames-logdir=/var/log
.if defined(WITHOUT_STATIC)
CONFIGURE_ARGS+=	--disable-static
PLIST_SUB+=	STATIC="@comment "
.else
PLIST_SUB+=	STATIC=""
.endif

MAN1=		catior.1 genior.1 nameclt.1 obuildtree.1 ols.1 omake.1 \
		omniNames.1 opriv.1 oshadow.1

pre-configure:
	@ ${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
.for manpage in ${MAN1}
	@ ${INSTALL_MAN} ${WRKSRC}/man/man1/${manpage} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@ ${MKDIR} ${DOCSDIR}
	@ cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST README.unix \
	  ReleaseNotes_${PORTVERSION}.txt ${DOCSDIR}
	@ ${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${DOCSDIR} -
.endif

.include <bsd.port.mk>
