PORTNAME=	note
DISTVERSION=	1.3.26
CATEGORIES=	deskutils perl5
MASTER_SITES=	http://www.daemon.de/idisk/Apps/note/

MAINTAINER=	rigoletto@FreeBSD.org
COMMENT=	Console based tool to handle encrypted notes

LICENSE=	GPLv1

RUN_DEPENDS=	p5-YAML>=0.1:textproc/p5-YAML \
		p5-Config-General>0:devel/p5-Config-General

USES=		perl5
USE_PERL5=	configure
NO_ARCH=	yes

OPTIONS_DEFINE=		EXAMPLES MYSQL PWSAFE3
OPTIONS_DEFAULT=	BLOWFISH DES IDEA MYSQL PWSAFE3

MYSQL_RUN_DEPENDS=	p5-DBD-mysql>0:databases/p5-DBD-mysql \
			p5-DBI>0:databases/p5-DBI

PWSAFE3_DESC=		Password Safe v3 backend
PWSAFE3_RUN_DEPENDS=	p5-Crypt-PWSafe3>0:security/p5-Crypt-PWSafe3

OPTIONS_GROUP=		CRYPTO
OPTIONS_GROUP_CRYPTO=	DES IDEA BLOWFISH

CRYPTO_DESC=		Encryption support
CRYPTO_RUN_DEPENDS=	p5-Crypt-CBC>0:security/p5-Crypt-CBC \
			p5-Crypt-Rijndael>0:security/p5-Crypt-Rijndael

BLOWFISH_DESC=		BlowFish block cipher support
BLOWFISH_RUN_DEPENDS=	p5-Crypt-Blowfish>0:security/p5-Crypt-Blowfish \
			${CRYPTO_RUN_DEPENDS}

DES_DESC=		DES block cipher support
DES_RUN_DEPENDS=	p5-Crypt-DES>0:security/p5-Crypt-DES \
			${CRYPTO_RUN_DEPENDS}

IDEA_DESC=		IDEA block cipher support
IDEA_RUN_DEPENDS=	p5-Crypt-IDEA>0:security/p5-Crypt-IDEA \
			${CRYPTO_RUN_DEPENDS}

post-patch:
	@${REINPLACE_CMD} -e 's|{{(|{\\{(|g' \
		${WRKSRC}/bin/note

post-install:
	${MKDIR} ${STAGEDIR}${EXAMPLESDIR}
	(cd ${WRKSRC}/config && ${COPYTREE_SHARE} . ${STAGEDIR}${EXAMPLESDIR})

.include <bsd.port.mk>
