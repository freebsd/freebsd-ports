# New ports collection makefile for:   sqsh
# Date created:		14 Jan 2000
# Whom:			Domas Mituzas <midom@dammit.lt>
#
# $FreeBSD$

PORTNAME=	sqsh
PORTVERSION=	1.7
PORTREVISION=	1
CATEGORIES=	databases
MASTER_SITES=	http://www.voicenet.com/~gray/
EXTRACT_SUFX=	-src.tar.gz

MAINTAINER=	midom@dammit.lt

LIB_DEPENDS=	tds.0:${PORTSDIR}/databases/freetds \
		intl.2:${PORTSDIR}/devel/gettext
BUILD_DEPENDS=	bash:${PORTSDIR}/shells/bash1

GNU_CONFIGURE=	yes

MAN1=	sqsh.1

post-patch:
.for file in configure autoconf/install-man
	@${PERL} -pi -e "s|%%LOCALBASE%%|${LOCALBASE}|g" ${WRKSRC}/${file}
.endfor

.include <bsd.port.mk>
