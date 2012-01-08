# New ports collection makefile for:	shairport
# Date created:				2011.09.30
# Whom:					Aldis Berjoza <graudeejs@gmail.com>
#
# $FreeBSD$
#

PORTNAME=	shairport
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/miks/${PORTNAME}/
DISTNAME=	miks-${PORTNAME}-${REV}

MAINTAINER=	miks.mikelsons@gmail.com
COMMENT=	Airtunes emulator

LIB_DEPENDS=	ao.4:${PORTSDIR}/audio/libao
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64 \
		${SITE_PERL}/Getopt/Long.pm:${PORTSDIR}/devel/p5-Getopt-Long \
		${SITE_PERL}/URI/Escape.pm:${PORTSDIR}/net/p5-URI \
		${SITE_PERL}/${PERL_ARCH}/Crypt/OpenSSL/RSA.pm:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		${SITE_PERL}/${PERL_ARCH}/Digest/MD5.pm:${PORTSDIR}/security/p5-Digest-MD5 \
		${SITE_PERL}/HTTP/Request.pm:${PORTSDIR}/www/p5-HTTP-Message \
		avahi-publish-service:${PORTSDIR}/net/avahi-app

USE_GMAKE=	yes
USE_PERL5_RUN=	5.10.0+
USE_OPENSSL=	yes
USE_GNOME=	pkgconfig

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	PERL=${PERL}

PLIST_FILES=	bin/${PORTNAME} bin/hairtunes bin/${PORTNAME}.pl
PORTDOCS=	README.md

REV=		b1cb9ea

post-patch:
	@${REINPLACE_CMD} -e 's|avahi-|${LOCALBASE}/bin/avahi-|g' \
		-e 's|$$FindBin.*|"${PREFIX}/bin/hairtunes";|' \
		-e '/use FindBin;/d;s|/usr/bin/env perl|${PERL}|' \
		${WRKSRC}/shairport.c ${WRKSRC}/shairport.pl

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${PREFIX}/bin
.for file in ${PORTNAME} hairtunes
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor
.if !defined(NOPORTDOCS)
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${DOCSDIR}
.endfor
.endif

post-install:
	@${CAT} ${PKGMESSAGE}

.include <bsd.port.mk>
