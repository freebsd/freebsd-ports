# Created by: Vladimir Kurtikov <vk@vk.pp.ru>
# $FreeBSD$

PORTNAME=	bforce
PORTVERSION=	0.22.8
PORTREVISION=	2
CATEGORIES=	comms
MASTER_SITES=	ftp://fido.kuzbass.ru/pub/fileecho/DALLAS.SOFT/

MAINTAINER=	vk@vk.pp.ru
COMMENT=	Simple ifcico like Fidonet technology mailer

USES=		gmake tar:bzip2
GNU_CONFIGURE=	yes

CFLAGS+=	-fno-builtin

WRKSRC=		${WRKDIR}/${DISTNAME}/source
SUB_FILES=	pkg-message

do-install:
	@${MKDIR} ${STAGEDIR}${PREFIX}/etc/bforce
.for f in bforce.conf bforce.passwd bforce.subst freq.aliases freq.dirs
	${INSTALL_DATA} ${WRKSRC}/../examples/${f} \
		${STAGEDIR}${PREFIX}/etc/bforce/${f}.sample
.endfor
.for f in bforce bfindex bfstat nlookup
	${INSTALL_PROGRAM} ${WRKSRC}/bin/${f} ${STAGEDIR}${PREFIX}/bin
.endfor

.include <bsd.port.mk>
