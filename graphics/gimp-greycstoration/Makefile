# New ports collection makefile for:	gimp-greycstoration
# Date created:		6 March 2006
# Whom:			Elisey Savateev <b3k@mail.ru>
#
# $FreeBSD$
#

PORTNAME=	greycstoration
PORTVERSION=	0.2.0
PORTREVISION=	4
CATEGORIES=	graphics
MASTER_SITES=	http://www.haypocalc.com/perso/prog/greycstoration/ \
				http://bio3k.softboard.ru/uploads/arch/
PKGNAMEPREFIX=	gimp-

MAINTAINER=	b3k@mail.ru
COMMENT=	Gimp plugin used for noise reduction

BUILD_DEPENDS=	gimp>0:${PORTSDIR}/graphics/gimp \
	${SITE_PERL}/mach/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser
RUN_DEPENDS=	gimp>0:${PORTSDIR}/graphics/gimp \
	${SITE_PERL}/mach/XML/Parser.pm:${PORTSDIR}/textproc/p5-XML-Parser

GNU_CONFIGURE=	yes
USE_BZIP2=	yes
USE_GNOME=	gtk20
USE_PERL5=	yes

# Redifine this if you need
PLUGIN_DIR?=	libexec/gimp/2.2/plug-ins

PLIST_SUB=	PLUGIN_DIR=${PLUGIN_DIR}

post-extract:
	@${REINPLACE_CMD} -e 's|$$(GIMP_LIBDIR)/plug-ins|${PREFIX}/${PLUGIN_DIR}|g' ${WRKSRC}/src/Makefile.in ${WRKSRC}/src/Makefile.am

.include <bsd.port.mk>
