# New ports collection makefile for:	Jcode
# Date created:		7 Nov 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jcode
PORTVERSION=	0.79
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DANKOGAI

MAINTAINER=	kuriyama@FreeBSD.org

BUILD_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${LOCALBASE}/lib/perl5/site_perl/${PERL_VER}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64

PERL_CONFIGURE=	yes
MAN3=		Jcode.3 Jcode::Unicode.3 Jcode::Unicode::Constants.3 \
		Jcode::Unicode::NoXS.3
MANPREFIX=	${PREFIX}/lib/perl5/${PERL_VERSION}

.include <bsd.port.pre.mk>

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-configure:
.for DIR in Unicode Jcode
	${PERL} -pi -e "s:CCFLAGS = :CCFLAGS = ${CFLAGS} :g ; \
			s:CC = cc:CC = ${CC}:g" ${WRKSRC}/${DIR}/Makefile
.endfor

.include <bsd.port.post.mk>
