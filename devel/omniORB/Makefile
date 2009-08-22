# New ports collection makefile for:	omniORB
# Date created:		14 May 1997
# Whom:			ejc@bazzle.com
#
# $FreeBSD$
#

PORTNAME=	omniORB
PORTVERSION=	4.1.3
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME}%20${PORTVERSION}

MAINTAINER=	sem@FreeBSD.org
COMMENT=	A robust high performance CORBA ORB for C++ and Python

PLIST_SUB+=	SONUM=${PORTVERSION:C/.*\.//}
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_OPENSSL=	yes
USE_GNOME=	pkgconfig
USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
BUILD_WRKSRC=	${CONFIGURE_WRKSRC}
INSTALL_WRKSRC=	${CONFIGURE_WRKSRC}
CONFIGURE_WRKSRC=	${WRKSRC}/build
CONFIGURE_SCRIPT=	../configure
CONFIGURE_ENV+=	CC=${CC} CFLAGS="${CFLAGS}" CXX=${CXX} CXXFLAGS="${CXXFLAGS}" \
		CPP=${CPP} PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=${OPENSSLBASE} \
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
	@${REINPLACE_CMD} -e 's#-pthread|-lc_r#${PTHREAD_LIBS}#' \
		-e 's#-O2#${CFLAGS}#g' ${WRKSRC}/mk/beforeauto.mk.in

pre-configure:
	@${MKDIR} ${CONFIGURE_WRKSRC}

post-install:
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${PYTHON_SITELIBDIR}/omniidl')"
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${PYTHON_SITELIBDIR}/omniidl_be')"
.for manpage in ${MAN1}
	@${INSTALL_MAN} ${WRKSRC}/man/man1/${manpage} ${MANPREFIX}/man/man1
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST.txt README.unix \
	 ReleaseNotes.txt ${DOCSDIR}
	@${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${DOCSDIR} -
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample.cfg ${EXAMPLESDIR}/omniORB.cfg
.endif

.include <bsd.port.mk>
