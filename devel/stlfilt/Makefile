# ex:ts=8
# Ports collection makefile for:	stlfilt
# Date created:			Mar 12, 2004
# Whom:				ijliao
#
# $FreeBSD$
#

PORTNAME=	stlfilt
PORTVERSION=	20050629
CATEGORIES=	devel
MASTER_SITES=	http://www.bdsoft.com/dist/
DISTNAME=	g${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	barner@FreeBSD.org
COMMENT=	An STL Error Message Decryptor for C++

EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_REINPLACE=	yes
USE_PERL5_RUN=	yes
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/gSTLFilt.pl bin/gfilt

post-patch:
	@${REINPLACE_CMD} -e "s,[$$]HOME,${PREFIX}/bin," ${WRKSRC}/gfilt

do-install:
.for file in gSTLFilt.pl gfilt
	@${INSTALL_SCRIPT} ${WRKSRC}/${file} ${PREFIX}/bin
.endfor

.include <bsd.port.mk>
