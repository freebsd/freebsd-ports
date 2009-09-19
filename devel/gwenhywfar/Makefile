# New ports collection makefile for:	gwenhywfar
# Date created:		2005-05-05
# Whom:			Peter Cornelius <pcc.at.gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gwenhywfar
PORTVERSION=	3.9.0
PORTREVISION=	2
CATEGORIES=	devel net security
MASTER_SITES=	http://www2.aquamaniac.de/sites/download/
DISTFILES=	download.php\?package=01\&release=25\&file=01\&dummy=gwenhywfar-${PORTVERSION}.tar.gz

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-platform helper library for networking and security applications

LIB_DEPENDS=	gnutls.40:${PORTSDIR}/security/gnutls

OPTIONS=	MEMDEBUG "Enable memory debugger statistic" off \
		PORTDOCS "Install documentation (requires doxygen)" off

USE_AUTOTOOLS=	libtool:22
USE_GMAKE=	yes
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
USE_LDCONFIG=	${PREFIX}/lib \
		${PREFIX}/lib/gwenhywfar/plugins/47/ct \
		${PREFIX}/lib/gwenhywfar/plugins/47/dbio \
		${PREFIX}/lib/gwenhywfar/plugins/47/configmgr
CFLAGS+=	-I${LOCALBASE}/include
CPPFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

.if !defined(NOPORTEXAMPLES)
# Examples to be installed from ${WRKSRC}/doc
PORTEXAMPLES=	STYLE \
		apidoc.h \
		db2.png \
		plugindescr.xml \
		plugindescr.xsd \
		plugindescr.xsd.in \
		testdialog.xml
.endif

.include <bsd.port.pre.mk>

# Enable printing of memory debugger statistic at runtime.
.if defined(WITH_MEMDEBUG)
CONFIGURE_ARGS+=	--enable-memtrace
.endif

.if defined(WITH_PORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
CONFIGURE_ARGS+=	--enable-full-doc
PORTDOCS=	*
.endif

post-build:
.if !defined(NOPORTDOCS) && defined(WITH_PORTDOCS)
	@cd ${WRKSRC} && ${GMAKE} srcdoc
.endif

post-install:
.if !defined(NOPORTDOCS) && defined(WITH_PORTDOCS)
	@${ECHO_CMD} Installing documentation...
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} apidoc -mindepth 1 \! -type d \
		-exec ${ECHO_CMD} "{} -> ${DOCSDIR}/{}" \; \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DOCSDIR} \;
.endif
.if !defined(NOPORTEXAMPLES)
	@${ECHO_CMD} Installing examples...
	${MKDIR} ${EXAMPLESDIR}
.for file in ${PORTEXAMPLES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${EXAMPLESDIR}
.endfor
.endif

.include <bsd.port.post.mk>
