# New ports collection makefile for:	streamripper
# Date created:		6 Apr 2000
# Whom:			Trevor Johnson
#
# $FreeBSD$
#

PORTNAME=	streamripper
PORTVERSION=	1.61.3
CATEGORIES=	audio
MASTER_SITES=	${MASTER_SITE_SOURCEFORGE}
MASTER_SITE_SUBDIR=	streamripper

MAINTAINER=	trevor@FreeBSD.org
COMMENT=	Splits SHOUTcast stream into tracks

LIB_DEPENDS=	iconv.3:${PORTSDIR}/converters/libiconv \
		mad.2:${PORTSDIR}/audio/libmad

IGNORE=		fails to split up streams into tracks

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	CPPFLAGS="-I${LOCALBASE}/include" \
		LDFLAGS="-L${LOCALBASE}/lib"

PLIST_FILES=	bin/streamripper
MAN1=		streamripper.1

.include <bsd.port.mk>
