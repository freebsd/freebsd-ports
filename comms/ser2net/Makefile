# Created by: Devon H. O'Dell <devon.odell@coyotepoint.com>
# $FreeBSD$

PORTNAME=	ser2net
PORTVERSION=	2.8
CATEGORIES=	comms net
MASTER_SITES=	SF/${PORTNAME}/${PORTNAME}

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Allows to access serial ports over IP

LICENSE=	GPLv2 # (or later)

OPTIONS_DEFINE=	DOCS

USE_RC_SUBR=	${PORTNAME}

GNU_CONFIGURE=	yes

MAN8=		${PORTNAME}.8
PORTDOCS=	AUTHORS ChangeLog INSTALL NEWS README
PLIST_FILES=	sbin/${PORTNAME} etc/${PORTNAME}.conf.sample

NO_STAGE=	yes
.include <bsd.port.options.mk>

post-patch:
.for i in ${PORTNAME}.c ${PORTNAME}.8
	@${REINPLACE_CMD} -e \
		's!/etc!${PREFIX}/etc!g' ${WRKSRC}/${i}
.endfor
.for i in ${PORTNAME}.conf
	@${REINPLACE_CMD} -e \
		's!ttyS!cuad!g' ${WRKSRC}/${i}
.endfor

do-install:
	(cd ${WRKSRC} \
		&& ${INSTALL_PROGRAM} ${PORTNAME} ${PREFIX}/sbin \
		&& ${INSTALL_MAN} ${PORTNAME}.8 ${MAN8PREFIX}/man/man8 \
		&& ${INSTALL_DATA} ${PORTNAME}.conf ${PREFIX}/etc/${PORTNAME}.conf.sample)
.if ${PORT_OPTIONS:MDOCS}
	@${MKDIR} ${DOCSDIR}
.for i in ${PORTDOCS}
	(cd ${WRKSRC} && ${INSTALL_DATA} ${i} ${DOCSDIR})
.endfor
.endif

.include <bsd.port.mk>
