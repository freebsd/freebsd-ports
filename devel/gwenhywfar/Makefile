# New ports collection makefile for:	gwenhywfar
# Date created:		2005-05-05
# Whom:			Peter Cornelius <pcc.at.gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gwenhywfar
PORTVERSION=	2.6.2
PORTREVISION=	1
CATEGORIES=	devel net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Multi-platform helper library for networking and security applications

OPTIONS=	MEMDEBUG "Enable memory debugger statistic" off \
		PORTDOCS "Install documentation (requires doxygen)" off

USE_AUTOTOOLS=	libtool:15
GNU_CONFIGURE=	yes
USE_GETTEXT=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
USE_LDCONFIG=	${PREFIX}/lib \
		${PREFIX}/lib/gwenhywfar/plugins/38/crypttoken \
		${PREFIX}/lib/gwenhywfar/plugins/38/dbio \
		${PREFIX}/lib/gwenhywfar/plugins/38/storage

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
	@cd ${WRKSRC} && ${MAKE} srcdoc
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
