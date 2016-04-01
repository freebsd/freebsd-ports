# Created by: Sunpoet Po-Chuan Hsieh <sunpoet@sunpoet.net>
# $FreeBSD$

PORTNAME=	mp3lint
PORTVERSION=	0.9
PORTREVISION=	1
CATEGORIES=	audio perl5
MASTER_SITES=	http://erislabs.net/ianb/projects/${PORTNAME}/ \
		LOCAL/sunpoet

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Configurable tool to check collections of audio files

LICENSE=	GPLv2
LICENSE_FILE=	${WRKSRC}/COPYING

BUILD_DEPENDS=	libmp3-archive-perl>=0:audio/libmp3-archive-perl
RUN_DEPENDS:=	${BUILD_DEPENDS}

NO_ARCH=	yes
USE_PERL5=	configure
USES=		perl5

post-patch:
	@${REINPLACE_CMD} -e '/^INSTALLSYSCONFDIR/ s|/etc|${PREFIX}&|' ${WRKSRC}/Makefile.PL
# It fails to build with error message as follows:
# Can't write-open blib/man5/mp3lintrc.5: No such file or directory at /usr/local/lib/perl5/5.xx.y/ExtUtils/Command/MM.pm line zzz.
#	@${MKDIR} ${WRKSRC}/blib/man5/

.include <bsd.port.mk>
