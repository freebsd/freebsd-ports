# Created by: ejc@bazzle.com
# $FreeBSD$

PORTNAME=	omniORB
PORTVERSION=	4.1.7
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	SF/${PORTNAME:tl}/${PORTNAME}/${PORTNAME}-${PORTVERSION}
PKGNAMESUFFIX=	41

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Robust high performance CORBA ORB for C++ and Python

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

DEPRECATED=	Legacy version please consider using devel/omniORB
EXPIRATION_DATE=2019-02-15

USES=		gmake pkgconfig python:2.7 shebangfix ssl tar:bzip2

CONFLICTS=	omniORB-4.2.*

PLIST_SUB+=	SONUM=${PORTVERSION:C/.*\.//}
GNU_CONFIGURE=	yes
SHEBANG_FILES=	src/tool/omniidl/python/scripts/omniidlrun.py
USE_LDCONFIG=	yes
MAKEFILE=	GNUmakefile
CONFIGURE_ENV+=	PYTHON=${PYTHON_CMD}
CONFIGURE_ARGS=	--datadir=${DATADIR} --with-openssl=${OPENSSLBASE} \
		--with-omniORB-config=${PREFIX}/etc/omniORB.cfg \
		--with-omniNames-logdir=/var/log

OPTIONS_DEFINE=	DOCS EXAMPLES STATIC
OPTIONS_DEFAULT=	STATIC
OPTIONS_SUB=	yes
STATIC_CONFIGURE_OFF=	--disable-static

BINS=	catior convertior genior nameclt omkdepend omniMapper omniNames omnicpp

pre-configure:
	@${REINPLACE_CMD} -e 's#-O2#${CFLAGS}#g' ${WRKSRC}/mk/beforeauto.mk.in
	@${REINPLACE_CMD} -e 's#%%STAGEDIR%%%%PREFIX%%#${STAGEDIR}${PREFIX}#g' \
		${WRKSRC}/contrib/pkgconfig/GNUmakefile.in

post-install:
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/lib/lib*.so \
		${STAGEDIR}${PYTHON_SITELIBDIR}/_omniidlmodule.so
	${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl')"
	${PYTHON_CMD} -c "import compileall; compileall.compile_dir('${STAGEDIR}${PYTHON_SITELIBDIR}/omniidl_be')"
	cd ${WRKSRC}/man/man1 && ${INSTALL_MAN} *.1 ${STAGEDIR}${MAN1PREFIX}/man/man1
	cd ${WRKSRC}/man/man8 && ${INSTALL_MAN} *.8 ${STAGEDIR}${MAN8PREFIX}/man/man8
.for bin in ${BINS}
	@${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/${bin}
.endfor

post-install-DOCS-on:
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} README.FIRST.txt README.unix \
		ReleaseNotes.txt ${STAGEDIR}${DOCSDIR}
	${TAR} cCf ${WRKSRC}/doc - . | ${TAR} xUCf ${STAGEDIR}${DOCSDIR} -

post-install-EXAMPLES-on:
	@${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	${INSTALL_DATA} ${WRKSRC}/sample.cfg ${STAGEDIR}${EXAMPLESDIR}/omniORB.cfg

.include <bsd.port.mk>
