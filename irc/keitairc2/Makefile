# Created by: Makoto Matsushita <matusita@FreeBSD.org>
# $FreeBSD$

PORTNAME=		keitairc
PORTVERSION=		2.0
CATEGORIES=		irc
MASTER_SITES=		SFJP/${PORTNAME}/47485

MAINTAINER=	ports@FreeBSD.org
COMMENT=	IRC proxy for mobilephone that have a web interface

RUN_DEPENDS=	p5-POE-Component-IRC>=0:irc/p5-POE-Component-IRC \
		p5-URI>=0:net/p5-URI \
		p5-libwww>=0:www/p5-libwww \
		p5-HTML-Template>=0:www/p5-HTML-Template \
		p5-XML-Simple>=0:textproc/p5-XML-Simple \
		p5-Proc-Daemon>=0:devel/p5-Proc-Daemon \
		p5-AppConfig>=0:devel/p5-AppConfig

CONFLICTS=	keitairc-1.*

USES=		shebangfix perl5
NO_BUILD=	yes

SHEBANG_FILES=	keitairc

post-extract:
	${FIND} ${WRKSRC} -name .cvsignore | ${XARGS} ${RM} -r

post-patch:
	${FIND} ${WRKSRC} -name '*.orig' | ${XARGS} ${RM} -r
	${REINPLACE_CMD} -i '' -e "s,/usr/share/keitairc/lib,${DATADIR}/lib,"  \
		${WRKSRC}/keitairc
	${REINPLACE_CMD} -i '' -e "s,__KEITAIRC_DATA_DIR__,${DATADIR}/lib,"  \
		${WRKSRC}/lib/Keitairc/Config.pm

do-install:
	${INSTALL_SCRIPT} ${WRKSRC}/keitairc ${STAGEDIR}${PREFIX}/bin
	@${MKDIR} ${STAGEDIR}${DATADIR}
	(cd ${WRKSRC} && ${COPYTREE_SHARE} "doc etc lib" ${STAGEDIR}${DATADIR})

.include <bsd.port.mk>
