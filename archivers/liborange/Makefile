# New ports collection makefile for:	orange
# Date Created:				January 2005
# Whom:					Sam Lawrance <boris@brooknet.com.au>
#
# $FreeBSD$
#

PORTNAME=	orange
PORTVERSION=	0.3
PORTREVISION=	1
CATEGORIES=	archivers
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	synce

MAINTAINER=	lawrance@FreeBSD.org
COMMENT=	Extract Microsoft Cabinet files from self-extracting installers

LIB_DEPENDS=	synce.0:${PORTSDIR}/palm/synce-libsynce \
		rapi.2:${PORTSDIR}/palm/synce-librapi2 \
		dynamite.0:${PORTSDIR}/archivers/dynamite \
		unshield.0:${PORTSDIR}/archivers/unshield

GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ARGS=	--with-libsynce=${LOCALBASE}
USE_ICONV=	yes
INSTALLS_SHLIB=	yes

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|-Werror||' \
		${WRKSRC}/lib/Makefile.in \
		${WRKSRC}/src/Makefile.in
.if ${OSVERSION} < 500000
	@${REINPLACE_CMD} -e 's|<stdint.h>|<inttypes.h>|' ${WRKSRC}/lib/inno.h
.endif

.include <bsd.port.post.mk>
