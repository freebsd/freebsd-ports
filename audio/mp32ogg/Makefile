# ex:ts=8
# New ports collection makefile for:	mp32ogg
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp32ogg
PORTVERSION=	0.11
PORTREVISION=	2
CATEGORIES=	audio perl5
MASTER_SITES=	ftp://ftp.faceprint.com/pub/software/scripts/ \
		http://people.freebsd.org/~uqs/distfiles/
EXTRACT_SUFX=	# empty

MAINTAINER=	uqs@FreeBSD.org
COMMENT=	Convert MP3 files to Ogg Vorbis files

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		${SITE_PERL}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${SITE_PERL}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes
PLIST_FILES=	bin/mp32ogg

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/mp32ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp32ogg ${PREFIX}/bin

.include <bsd.port.mk>
