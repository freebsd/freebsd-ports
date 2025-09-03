PORTNAME=	omniORB
DISTVERSION=	${ABI_VER}.${ABI_MAJOR_VER}.${ABI_MINOR_VER}
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTNAME}-${DISTVERSION:S/-2//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Robust high performance CORBA ORB for C++ and Python
WWW=		http://omniorb.sourceforge.net/

LICENSE=	GPLv2

NOT_FOR_ARCHS=	armv7 i386 powerpc
NOT_FOR_ARCHS_REASON=	use of overloaded operator '[]' is ambiguous (with operand types

LIB_DEPENDS=	libzstd.so:archivers/zstd

USES=		gmake pkgconfig python shebangfix ssl tar:bzip2
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist

SHEBANG_FILES=	src/tool/omniidl/python2/scripts/omniidlrun.py \
		src/tool/omniidl/python3/scripts/omniidlrun.py

GNU_CONFIGURE=	yes
CONFIGURE_ARGS=	--datadir=${DATADIR} \
		--with-omniNames-logdir=/var/log \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-openssl=${OPENSSLBASE}
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}

MAKEFILE=	GNUmakefile

WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-2//}

PLIST_SUB+=		ABI_MAJOR_VER=${ABI_MAJOR_VER} \
			ABI_MINOR_VER=${ABI_MINOR_VER} \
			ABI_VER=${ABI_VER}

OPTIONS_DEFINE=		DOCS STATIC
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=		yes

STATIC_CONFIGURE_OFF=	--disable-static

ABI_VER=		4
ABI_MAJOR_VER=		3
ABI_MINOR_VER=		3

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#g' ${WRKSRC}/mk/beforeauto.mk.in
	@${REINPLACE_CMD} -e 's#$$(INSTALLLIBDIR)/pkgconfig#${STAGEDIR}${PREFIX}/libdata/pkgconfig#g' \
		${WRKSRC}/contrib/pkgconfig/GNUmakefile.in

post-install:
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl')"
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl_be')"
	${INSTALL_DATA} ${WRKSRC}/sample.cfg ${STAGEDIR}${PREFIX}/etc/omniORB.cfg.sample
	@cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} *.1 ${STAGEDIR}${PREFIX}/share/man/man1
	@cd ${WRKSRC}/man/man8 && ${INSTALL_MAN} *.8 ${STAGEDIR}${PREFIX}/share/man/man8
.for i in catior convertior omniMapper omniNames omnicpp nameclt omkdepend \
	genior
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.for i in libomniConnectionMgmt4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomniORB4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libCOSDynamic4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomnihttpTP4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomnihttpCrypto4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomnisslTP4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomniDynamic4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libCOS4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomniCodeSets4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomniZIOPDynamic4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER} \
	libomnithread.so.${ABI_VER}.${ABI_MAJOR_VER} \
	libomniZIOP4.so.${ABI_MAJOR_VER}.${ABI_MINOR_VER}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST.txt README.unix.txt \
	 ReleaseNotes.txt ${STAGEDIR}${DOCSDIR}
	@${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${STAGEDIR}${DOCSDIR} -

.include <bsd.port.mk>
