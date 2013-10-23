# Created by: ijliao
# $FreeBSD$

PORTNAME=	stlfilt
PORTVERSION=	20080203
CATEGORIES=	devel
MASTER_SITES=	http://www.bdsoft.com/dist/
DISTNAME=	g${PORTNAME}
EXTRACT_SUFX=	.tar

MAINTAINER=	eadler@FreeBSD.org
COMMENT=	STL Error Message Decryptor for C++

USES=		perl5
EXTRACT_CMD=	${TAR}
EXTRACT_BEFORE_ARGS=	-xf
EXTRACT_AFTER_ARGS=	# empty
USE_PERL5=	run
NO_BUILD=	yes
NO_WRKSUBDIR=	yes

PLIST_FILES=	bin/gSTLFilt.pl bin/gfilt

post-patch:
	@${REINPLACE_CMD} -e "s,[$$]HOME,${PREFIX}/bin," ${WRKSRC}/gfilt

do-install:
.for file in gSTLFilt.pl gfilt
	${INSTALL_SCRIPT} ${WRKSRC}/${file} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
