# Created by: ejc@bazzle.com
# $FreeBSD$

PORTNAME=	omniORB
DISTVERSION=	4.2.1-2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTNAME}-${DISTVERSION:S/-2//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Robust high performance CORBA ORB for C++ and Python

LICENSE=	GPLv2

CONFLICTS=	omniORB41-4.1.*
PLIST_SUB+=	SONUM=1
GNU_CONFIGURE=	yes
USE_OPENSSL=	yes
USES=		gmake pkgconfig python tar:bzip2
USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=${OPENSSLBASE} \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-omniNames-logdir=/var/log
OPTIONS_DEFINE=	DOCS STATIC
OPTIONS_DEFAULT=	DOCS STATIC
OPTIONS_SUB=	yes
STATIC_CONFIGURE_OFF=	--disable-static
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-2//}

post-patch:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#g' ${WRKSRC}/mk/beforeauto.mk.in
	@${REINPLACE_CMD} -e 's#%%STAGEDIR%%%%PREFIX%%#${STAGEDIR}${PREFIX}#g' \
		${WRKSRC}/contrib/pkgconfig/GNUmakefile.in

post-install:
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl')"
	@${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl_be')"
	${INSTALL_DATA} ${WRKSRC}/sample.cfg ${STAGEDIR}${PREFIX}/etc/omniORB.cfg.sample
	@cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} *.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	@cd ${WRKSRC}/man/man8 && ${INSTALL_MAN} *.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.for i in catior convertior omniMapper omniNames omnicpp nameclt omkdepend genior
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${i}
.endfor
.for i in libomniDynamic4.so.2.1 libomnisslTP4.so.2.1 libCOS4.so.2.1 \
	libomniCodeSets4.so.2.1 libomniZIOPDynamic4.so.2.1 libomniZIOP4.so.2.1 \
	libomniConnectionMgmt4.so.2.1 libomniORB4.so.2.1 libCOSDynamic4.so.2.1 \
	libomnithread.so.4.0
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/_omniidlmodule.so.4.2

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST.txt README.unix.txt \
	 ReleaseNotes.txt ${STAGEDIR}${DOCSDIR}
	@${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${STAGEDIR}${DOCSDIR} -

.include <bsd.port.mk>
