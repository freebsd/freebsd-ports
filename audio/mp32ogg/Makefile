# ex:ts=8
# New ports collection makefile for:	mp32ogg
# Date created:			Nov 4, 2001
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	mp32ogg
PORTVERSION=	0.11
CATEGORIES=	audio perl5
MASTER_SITES=	ftp://ftp.faceprint.com/pub/software/scripts/
EXTRACT_SUFX=	# empty

MAINTAINER=	ports@FreeBSD.org

PORTCOMMENT=	Convert MP3 files to Ogg Vorbis files

RUN_DEPENDS=	mpg123:${PORTSDIR}/audio/mpg123 \
		oggenc:${PORTSDIR}/audio/vorbis-tools \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/MP3/Info.pm:${PORTSDIR}/audio/p5-MP3-Info \
		${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/String/ShellQuote.pm:${PORTSDIR}/textproc/p5-String-ShellQuote

USE_PERL5=	yes
NO_WRKSUBDIR=	yes
EXTRACT_CMD=	${CP}
EXTRACT_BEFORE_ARGS=	#
EXTRACT_AFTER_ARGS=	${WRKSRC}/${PORTNAME}
NO_BUILD=	yes

post-patch:
	@${PERL} -pi -e "s,%%LOCALBASE%%,${LOCALBASE},g" ${WRKSRC}/mp32ogg

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/mp32ogg ${PREFIX}/bin

.include <bsd.port.mk>
