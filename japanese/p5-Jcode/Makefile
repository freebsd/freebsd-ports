# New ports collection makefile for:	Jcode
# Date created:		7 Nov 1999
# Whom:			Jun Kuriyama <kuriyama@FreeBSD.org>
#
# $FreeBSD$
#

PORTNAME=	Jcode
PORTVERSION=	0.87
CATEGORIES=	japanese perl5
MASTER_SITES=	${MASTER_SITE_PERL_CPAN}
MASTER_SITE_SUBDIR=	../../authors/id/D/DA/DANKOGAI

MAINTAINER=	kuriyama@FreeBSD.org
COMMENT=	Perl extension interface to convert Japanese text

PERL_CONFIGURE=	yes
MAN3=		Jcode.3 Jcode::Unicode.3 Jcode::Unicode::Constants.3 \
		Jcode::Unicode::NoXS.3

PKGNAMEPREFIX:=	${PKGNAMEPREFIX}p5-

post-configure:
.for DIR in Unicode
	${PERL} -pi -e "s:CCFLAGS = :CCFLAGS = ${CFLAGS} :g ; \
			s:CC = cc:CC = ${CC}:g" ${WRKSRC}/${DIR}/Makefile
.endfor

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500804
BUILD_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
RUN_DEPENDS=	${SITE_PERL}/${PERL_ARCH}/MIME/Base64.pm:${PORTSDIR}/converters/p5-MIME-Base64
.endif

.include <bsd.port.post.mk>
