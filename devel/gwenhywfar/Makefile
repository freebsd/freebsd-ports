# New ports collection makefile for:	gwenhywfar
# Date created:		2005-05-05
# Whom:			Peter Cornelius <pcc.at.gmx.net>
#
# $FreeBSD$
#

PORTNAME=	gwenhywfar
PORTVERSION=	1.13.2
CATEGORIES=	devel net security
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Multi-platform helper library for networking and security applications

OPTIONS=	SSLDEBUG "Enable gwenhywfar SSL debug (if SSL enabled)" off \
		MEMDEBUG "Enable memory debugger statistic" off

USE_LIBTOOL_VER=15
USE_GETTEXT=	yes
USE_OPENSSL=	yes
CONFIGURE_TARGET=--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
INSTALLS_SHLIB=	yes
LDCONFIG_DIRS+=	%%PREFIX%%/lib/gwenhywfar/plugins/17/dbio
ALL_TARGET=	all

# Examples to be installed from ${WRKSRC}/doc
EXAMPLE_FILES=	STYLE \
		apidoc.h \
		db2.png \
		plugindescr.xml \
		plugindescr.xsd \
		plugindescr.xsd.in \
		testdialog.xml

.if !defined(NOPORTDOCS)
BUILD_DEPENDS+=	doxygen:${PORTSDIR}/devel/doxygen
ALL_TARGET+=	srcdoc
PORTDOCS=*
.endif

.include <bsd.port.pre.mk>

.if defined(WITH_SSLDEBUG)
# Enable appending of SSL connection in/output to /tmp/{read|written}.bin.
CFLAGS+=	-DGWEN_SSL_DEBUG
.endif

# Enable printing of memory debugger statistic at runtime.
.if defined(WITH_MEMDEBUG)
CFLAGS+=	-DGWEN_MEMORY_DEBUG
.endif

post-install:
.if !defined(NOPORTDOCS)
	@${ECHO_CMD} Installing documentation...
	${MKDIR} ${EXAMPLESDIR}
.for file in ${EXAMPLE_FILES}
	${INSTALL_DATA} ${WRKSRC}/doc/${file} ${EXAMPLESDIR}
.endfor
	${MKDIR} ${DOCSDIR}
	@cd ${WRKSRC} && ${FIND} apidoc -mindepth 1 \! -type d \
		-exec ${ECHO_CMD} "{} -> ${DOCSDIR}/{}" \; \
		-exec ${INSTALL_DATA} ${WRKSRC}/{} ${DOCSDIR} \;
.endif

.include <bsd.port.post.mk>
