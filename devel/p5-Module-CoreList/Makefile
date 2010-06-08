# New ports collection makefile for:	devel/p5-Module-CoreList
# Date created:				Aug 27 2003
# Whom:					Autrijus Tang <autrijus@autrijus.org>
#
# $FreeBSD$
#

PORTNAME=	Module-CoreList
PORTVERSION=	2.34
CATEGORIES=	devel perl5
MASTER_SITES=	CPAN
PKGNAMEPREFIX=	p5-

MAINTAINER=	lth@FreeBSD.org
COMMENT=	See what modules shipped with versions of perl

PERL_CONFIGURE=	yes

MAN1=		p5corelist.1
MAN3=		Module::CoreList.3

SUB_FILES=	pkg-install

.include <bsd.port.pre.mk>

.if ${PERL_LEVEL} < 500809
PLIST_FILES+=	bin/corelist
.endif

pre-patch:
	@${MV} ${WRKSRC}/corelist ${WRKSRC}/p5corelist
	@${PERL} -pi -e 's,^corelist$$,p5corelist,' ${WRKSRC}/MANIFEST
	@${PERL} -pi -e 's,corelist,p5corelist,' ${WRKSRC}/Makefile.PL ${WRKSRC}/t/pod.t

post-install:
	@${SH} ${PKGINSTALL} ${PKGNAME} POST-INSTALL

.include <bsd.port.post.mk>
