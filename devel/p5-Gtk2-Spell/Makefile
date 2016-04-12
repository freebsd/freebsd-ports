# Created by: Jose Alonso Cardenas Marquez <acardenas@bsd.org.pe>
# $FreeBSD$

PORTNAME=	Gtk2-Spell
PORTVERSION=	1.04
PORTREVISION=	1
CATEGORIES=	devel perl5
MASTER_SITES=	SF/gtk2-perl/Gtk2_Spell/${PORTVERSION}
PKGNAMEPREFIX=	p5-

MAINTAINER=	acm@FreeBSD.org
COMMENT=	Perl interface to the Gtk2Spell library

LICENSE=	LGPL21

BUILD_DEPENDS=	p5-Cairo>=0:graphics/p5-Cairo \
		p5-ExtUtils-Depends>=0:devel/p5-ExtUtils-Depends \
		p5-ExtUtils-PkgConfig>=0:devel/p5-ExtUtils-PkgConfig \
		p5-Glib2>=1.001:devel/p5-Glib2 \
		p5-Gtk2>=1.001:x11-toolkits/p5-Gtk2
LIB_DEPENDS=	libgtkspell.so:textproc/gtkspell

USES=		perl5
USE_PERL5=	configure

post-patch:
	@${REINPLACE_CMD} -e 's=1.00rc2=1.001=g' ${WRKSRC}/Makefile.PL

post-install:
	${CHMOD} u+w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gtk2/Spell/Spell.so
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gtk2/Spell/Spell.so
	${CHMOD} u-w ${STAGEDIR}${PREFIX}/${SITE_ARCH_REL}/auto/Gtk2/Spell/Spell.so

.include <bsd.port.mk>
