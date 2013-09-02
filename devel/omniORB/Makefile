# Created by: ejc@bazzle.com
# $FreeBSD$

PORTNAME=	omniORB
PORTVERSION=	4.1.6
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:L}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
MAINTAINER=	sem@FreeBSD.org
COMMENT=	A robust high performance CORBA ORB for C++ and Python

PLIST_SUB+=	SONUM=${PORTVERSION:C/.*\.//}
USE_GCC=	any
GNU_CONFIGURE=	yes
USE_PYTHON=	yes
USE_OPENSSL=	yes
USES=		gmake pkgconfig
USE_BZIP2=	yes
USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=${OPENSSLBASE} \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-omniNames-logdir=/var/log
.if defined(WITHOUT_STATIC)
CONFIGURE_ARGS+=	--disable-static
PLIST_SUB+=	STATIC="@comment "
.else
PLIST_SUB+=	STATIC=""
.endif

MAN1=		catior.1 convertior.1 genior.1 nameclt.1 omniidl.1
MAN8=		omniMapper.8 omniNames.8

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#g' ${WRKSRC}/mk/beforeauto.mk.in

post-install:
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${PYTHON_SITELIBDIR}/omniidl')"
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${PYTHON_SITELIBDIR}/omniidl_be')"
	@cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} ${MAN1} ${MAN1PREFIX}/man/man1
	@cd ${WRKSRC}/man/man8 && ${INSTALL_MAN} ${MAN8} ${MAN8PREFIX}/man/man8
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST.txt README.unix \
	 ReleaseNotes.txt ${DOCSDIR}
	@${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${DOCSDIR} -
	@${MKDIR} ${EXAMPLESDIR}
	@${INSTALL_DATA} ${WRKSRC}/sample.cfg ${EXAMPLESDIR}/omniORB.cfg
.endif

.include <bsd.port.mk>
