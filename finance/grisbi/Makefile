# New ports collection makefile for:	grisbi
# Date created:		19 November 2002
# Whom:			Thierry Thomas <thierry@pompo.net>
#
# $FreeBSD$
#

PORTNAME=	grisbi
PORTVERSION=	0.5.1
CATEGORIES=	finance
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	${PORTNAME}

MAINTAINER=	thierry@FreeBSD.org
COMMENT=	A personnal accounting application

LIB_DEPENDS=	ofx.0:${PORTSDIR}/finance/libofx
.if !defined(WITHOUT_LATEX)
RUN_DEPENDS=	${UCS_CLASSDIR}/ucs.sty:${PORTSDIR}/print/latex-ucs
.endif

USE_BZIP2=	yes
USE_GETTEXT=	yes
USE_ICONV=	yes
USE_GMAKE=	yes
USE_GCC=	3.3
GNU_CONFIGURE=	yes
USE_GNOME=	gtk20 glib20 libxml2

TEXMF?=		share/texmf
UCS_CLASSDIR=	${LOCALBASE}/${TEXMF}/tex/latex/ucs

MAN1=		grisbi.1

CONFIGURE_ENV=	CPPFLAGS="-I${LOCALBASE}/include ${PTHREAD_CFLAGS}"	\
		LDFLAGS="-L${LOCALBASE}/lib ${PTHREAD_LIBS}"

.include <bsd.port.mk>
