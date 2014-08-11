# Created by: Aldis Berjoza <graudeejs@gmail.com>
# $FreeBSD$

PORTNAME=	shairport
PORTVERSION=	0.05
PORTREVISION=	1
CATEGORIES=	audio
MASTER_SITES=	http://cloud.github.com/downloads/miks/${PORTNAME}/
DISTNAME=	miks-${PORTNAME}-${REV}

MAINTAINER=	miks.mikelsons@gmail.com
COMMENT=	Airtunes emulator

LIB_DEPENDS=	libao.so:${PORTSDIR}/audio/libao
RUN_DEPENDS=	p5-MIME-Base64>=0:${PORTSDIR}/converters/p5-MIME-Base64 \
		p5-Getopt-Long>=0:${PORTSDIR}/devel/p5-Getopt-Long \
		p5-URI>=0:${PORTSDIR}/net/p5-URI \
		p5-Crypt-OpenSSL-RSA>=0:${PORTSDIR}/security/p5-Crypt-OpenSSL-RSA \
		p5-Digest-MD5>=0:${PORTSDIR}/security/p5-Digest-MD5 \
		p5-HTTP-Message>=0:${PORTSDIR}/www/p5-HTTP-Message \
		avahi-publish-service:${PORTSDIR}/net/avahi-app

USES=		gmake perl5 pkgconfig
USE_PERL5=	run
USE_OPENSSL=	yes

USE_RC_SUBR=	${PORTNAME}
SUB_LIST=	PERL=${PERL}

PLIST_FILES=	bin/${PORTNAME} bin/hairtunes bin/${PORTNAME}.pl
PORTDOCS=	README.md

REV=		b1cb9ea

OPTIONS_DEFINE=	DOCS

.include <bsd.port.options.mk>

post-patch:
	@${REINPLACE_CMD} -e 's|avahi-|${LOCALBASE}/bin/avahi-|g' \
		-e 's|$$FindBin.*|"${PREFIX}/bin/hairtunes";|' \
		-e '/use FindBin;/d;s|/usr/bin/env perl|${PERL}|' \
		${WRKSRC}/shairport.c ${WRKSRC}/shairport.pl
	@${REINPLACE_CMD} 's/-lssl/-lcrypto/' ${WRKSRC}/Makefile

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/${PORTNAME}.pl ${STAGEDIR}${PREFIX}/bin
.for file in ${PORTNAME} hairtunes
	${INSTALL_PROGRAM} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in ${PORTDOCS}
	${INSTALL_DATA} -p ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
.endif

.include <bsd.port.mk>
