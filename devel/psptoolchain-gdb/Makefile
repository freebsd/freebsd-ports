# New ports collection makefile for: psptoolchain-gdb
# Date created:        15 February 2009
# Whom:                Tassilo Philipp <tphilipp@potion-studios.com>
#
# $FreeBSD$
#

PORTNAME=		gdb
PORTVERSION=		6.4
CATEGORIES=		devel
MASTER_SITES=		${MASTER_SITE_GNU}
MASTER_SITE_SUBDIR=	${PORTNAME}/
PKGNAMEPREFIX=		psptoolchain-

MAINTAINER=		tphilipp@potion-studios.com
COMMENT=		PlayStation Portable development toolchain ${PORTNAME}

BUILD_DEPENDS=		${LOCALBASE}/psp/sdk/lib/libpspsdk.a:${PORTSDIR}/devel/psptoolchain-pspsdk-stage2

USE_BZIP2=		yes
USE_GMAKE=		yes

HAS_CONFIGURE=		yes
CONFIGURE_ARGS?=	--prefix=${PREFIX} --target="psp" --disable-nls --disable-install-libiberty

MAN1=			psp-gdb.1 \
			psp-gdbtui.1 \
			psp-run.1

# Disable installation of .info files and libiberty.
post-patch:
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/bfd/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(INFO_DEPS.*=)(.*)/\1#\2/' ${WRKSRC}/gdb/doc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:.*)(install-info.*)/\1#\2/' ${WRKSRC}/etc/Makefile.in
	@${REINPLACE_CMD} -E 's/^(install:)(.*)/\1#\2/' ${WRKSRC}/libiberty/Makefile.in

.include <bsd.port.mk>
