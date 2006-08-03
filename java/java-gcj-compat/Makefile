# New ports collection makefile for:	java-gcj-compat
# Date created:				29 July 2006
# Whom:					<maho@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	java-gcj-compat
PORTVERSION=	1.0.56 # intentionally not upgrading
PORTREVISION=	2
CATEGORIES=	java devel
MASTER_SITES=	ftp://sources.redhat.com/pub/rhug/

MAINTAINER=	maho@FreeBSD.org
COMMENT=	A collection of wrapper scripts, symlinks and jar files for GCJ

BUILD_DEPENDS+= ${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt
BUILD_DEPENDS+= gjdoc:${PORTSDIR}/java/gjdoc
BUILD_DEPENDS+= ecj:${PORTSDIR}/java/ecj-bootstrap

RUN_DEPENDS+= ${LOCALBASE}/libdata/ldconfig/gcc41-withgcjawt:${PORTSDIR}/lang/gcc41-withgcjawt
RUN_DEPENDS+= gjdoc:${PORTSDIR}/java/gjdoc
RUN_DEPENDS+= ecj:${PORTSDIR}/java/ecj-bootstrap

GCJVER=41
GNU_CONFIGURE=	yes
USE_GMAKE=	yes
USE_PYTHON=	yes
PLIST_SUB=	ARCH=${ARCH}
CONFIGURE_ARGS+="-with-origin-name=gcj41" "--with-gcc-suffix=41" \
		"--with-arch-directory=${ARCH}" "--disable-symlinks" \
		"--with-classpath-security=${LOCALBASE}/lib/security/classpath.security" \
		"--with-security-directory=${LOCALBASE}/etc/java/security/security.d"

pre-configure:
	@${REINPLACE_CMD} -e "s|%%LOCALBASE%%|${LOCALBASE}|" ${WRKSRC}/Makefile.in
	@${REINPLACE_CMD} -e "s|%%GCCSUFFIX%%|${GCJVER}|" ${WRKSRC}/java.c

post-install:
	@${LN} -sf ${PREFIX}/lib/jvm/java-1.4.2-gcj41-1.4.2.0 ${PREFIX}/lib/jvm/java-gcj

.include <bsd.port.mk>
