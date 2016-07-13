# Created by: Conrad Meyer <cem@FreeBSD.org>
# $FreeBSD$

PORTNAME=	elfutils
PORTVERSION=	0.163
PORTREVISION=	2
CATEGORIES=	devel
MASTER_SITES=	https://fedorahosted.org/releases/e/l/elfutils/$(PORTVERSION)/

MAINTAINER=	cem@FreeBSD.org
COMMENT=	Library for manipulating ELF files and partial implementation of binutils

LICENSE=	LGPL3 GPLv2 GPLv3
LICENSE_COMB=	multi
LICENSE_FILE_GPLv3=	${WRKSRC}/COPYING
LICENSE_FILE_GPLv2=	${WRKSRC}/COPYING-GPLV2
LICENSE_FILE_LGPL3=	${WRKSRC}/COPYING-LGPLV3

BUILD_DEPENDS=	gnulib>=0:devel/gnulib

OPTIONS_DEFINE=	NLS
OPTIONS_SUB=	yes

NLS_USES=	gettext
NLS_CONFIGURE_ENABLE=	nls

USES=		gmake libtool tar:bzip2
USE_AUTOTOOLS=	automake
USE_GCC=	4.9+
GNU_CONFIGURE=	yes

# Avoid conflict with binutils / elftoolchain programs with the same names:
CONFIGURE_ARGS+=	--program-prefix=eu-

post-patch:
	@cd $(WRKSRC) && ${AUTOMAKE}
	@${CP} -a \
	    $(LOCALBASE)/share/gnulib/lib/obstack.c \
	    $(LOCALBASE)/share/gnulib/lib/obstack.h \
	    $(LOCALBASE)/share/gnulib/lib/obstack_printf.c \
	    $(WRKSRC)/lib

.include <bsd.port.mk>
