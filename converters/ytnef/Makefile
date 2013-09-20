# Created by: Rodrigo Graeff <delphus@gmail.com>
# $FreeBSD$

PORTNAME=	ytnef
PORTVERSION=	2.6
PORTREVISION=	1
CATEGORIES=	converters mail
MASTER_SITES=	SF

MAINTAINER=	delphus@gmail.com
COMMENT=	Unpack data in MS Outlook TNEF format

LIB_DEPENDS=	ytnef.0:${PORTSDIR}/devel/libytnef
RUN_DEPENDS=	p5-MIME-Tools>=0:${PORTSDIR}/mail/p5-MIME-Tools

USES=		perl5
USE_PERL5=	run
GNU_CONFIGURE=	yes

CFLAGS+=	-I${LOCALBASE}/include
LDFLAGS+=	-L${LOCALBASE}/lib

PLIST_FILES=	bin/ytnef bin/ytnefprocess.pl bin/ytnefprint
PORTDOCS=	AUTHORS NEWS README

NO_STAGE=	yes
post-patch:
	@${REINPLACE_CMD} -e 's|^#!/usr/bin/perl|#!${PERL}|' \
		${WRKSRC}/src/ytnef/ytnefprocess.pl

post-install:
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
	cd ${WRKSRC} && ${INSTALL_DATA} ${PORTDOCS} ${DOCSDIR}
.endif

.include <bsd.port.mk>
