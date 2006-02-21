# New ports collection makefile for:	ytnef
# Date created:		21 Feb 2005
# Whom:			Rodrigo Graeff <delphus@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	ytnef
PORTVERSION=	2.6
CATEGORIES=	converters mail
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	delphus@gmail.com
COMMENT=	Unpack data in MS Outlook TNEF format

LIB_DEPENDS=	ytnef.0:${PORTSDIR}/devel/libytnef

USE_PERL5_RUN=	yes
GNU_CONFIGURE=	yes
USE_GETOPT_LONG=yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib
CONFIGURE_ENV+=	LDFLAGS="${LDFLAGS}"

CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}

PLIST_FILES=	bin/ytnef bin/ytnefprocess.pl bin/ytnefprint
PORTDOCS=	AUTHORS NEWS README

post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/src/ytnef/ytnefprocess.pl

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
