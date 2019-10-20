# Created by: ejc@bazzle.com
# $FreeBSD$

PORTNAME=	omniORB
DISTVERSION=	4.2.3
PORTREVISION=	1
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTNAME}-${DISTVERSION:S/-2//}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Robust high performance CORBA ORB for C++ and Python

LICENSE=	GPLv2

BROKEN_SSL=	openssl111
BROKEN_SSL_REASON_openssl111=	member access into incomplete type 'DH' (aka 'dh_st')

USES=		compiler:c++11-lang gmake pkgconfig python tar:bzip2 \
		shebangfix ssl

CONFLICTS=	omniORB41-4.1.*
SONUM=		3
PLIST_SUB+=	SONUM=${SONUM}
GNU_CONFIGURE=	yes
USE_LDCONFIG=	yes
USE_PYTHON=	py3kplist
MAKEFILE=	GNUmakefile
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=${OPENSSLBASE} \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-omniNames-logdir=/var/log
OPTIONS_DEFINE=	DOCS STATIC
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=	yes
STATIC_CONFIGURE_OFF=	--disable-static
WRKSRC=		${WRKDIR}/${PORTNAME}-${DISTVERSION:S/-2//}
SHEBANG_FILES=	src/tool/omniidl/python/scripts/omniidlrun.py \
		src/tool/omniidl/python3/scripts/omniidlrun.py

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
.for i in libomniDynamic4.so.2.${SONUM} libomnisslTP4.so.2.${SONUM} libCOS4.so.2.${SONUM} \
	libomniCodeSets4.so.2.${SONUM} libomniZIOPDynamic4.so.2.${SONUM} libomniZIOP4.so.2.${SONUM} \
	libomniConnectionMgmt4.so.2.${SONUM} libomniORB4.so.2.${SONUM} libCOSDynamic4.so.2.${SONUM} \
	libomnithread.so.4.1
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/${i}
.endfor
	@${STRIP_CMD} ${STAGEDIR}${PYTHONPREFIX_SITELIBDIR}/*.so

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	@cd ${WRKSRC} && ${INSTALL_DATA} COPYING README.FIRST.txt README.unix.txt \
	 ReleaseNotes.txt ${STAGEDIR}${DOCSDIR}
	@${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${STAGEDIR}${DOCSDIR} -

.include <bsd.port.mk>
