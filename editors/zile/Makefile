# New ports collection Makefile for:	zile
# Date created:		28 September 2000
# Whom:			jasone
#
# $FreeBSD$
#

PORTNAME=	zile
PORTVERSION=	2.2.12
CATEGORIES=	editors
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Small emacs-like text editor

USE_GETOPT_LONG=yes
USE_REINPLACE=	yes
GNU_CONFIGURE=	yes
CONFIGURE_TARGET=	--build=${MACHINE_ARCH}-portbld-freebsd${OSREL}
CONFIGURE_ENV=	LIBS="-lgnuregex"
CONFIGURE_ARGS=	--disable-allegro --disable-epocemx

MAN1=		zile.1
INFO=		zile
PLIST_FILES=	bin/zile %%DATADIR%%/AUTODOC %%DATADIR%%/FAQ %%DATADIR%%/HELP \
		%%DATADIR%%/TUTORIAL %%DATADIR%%/dotzile.sample
PLIST_DIRS=	%%DATADIR%%

.include <bsd.port.pre.mk>

.if ${OSVERSION} > 502010
GNU_REGEX_H=	gnu/regex.h
.else
GNU_REGEX_H=	gnuregex.h
.endif

post-patch:
	@${REINPLACE_CMD} -e \
		's|<regex\.h>|<${GNU_REGEX_H}>|g ; \
		 s|_regex_h|_${GNU_REGEX_H:S/\//_/g:S/./_/g}|g ; \
		 s|-pedantic||g' ${WRKSRC}/configure
	@${REINPLACE_CMD} -e \
		's|<regex\.h>|<${GNU_REGEX_H}>|g' ${WRKSRC}/src/search.c

.include <bsd.port.post.mk>
