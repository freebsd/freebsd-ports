# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
#
# $FreeBSD$
#

PORTNAME=	omniORB
PORTVERSION=	4.0.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME:L}

MAINTAINER=	sem@ciam.ru
COMMENT=	A robust high performance CORBA ORB for C++ and Python

CONFIGURE_WRKSRC=	${WRKSRC}/build
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_REINPLACE=	yes
USE_PYTHON=	yes
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

MAN1=		catior.1 genior.1 nameclt.1 omniNames.1 omniidl.1

post-patch:
	@${REINPLACE_CMD} -Ee 's#-pthread|-lc_r#${PTHREAD_LIBS}#' \
		${WRKSRC}/mk/beforeauto.mk.in

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
