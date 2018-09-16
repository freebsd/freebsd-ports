# Created by: Po-Chuan Hsieh <sunpoet@FreeBSD.org>
# $FreeBSD$

PORTNAME=	manpages
PORTVERSION=	0.6.1
CATEGORIES=	devel rubygems
MASTER_SITES=	RG

MAINTAINER=	sunpoet@FreeBSD.org
COMMENT=	Detect man pages within gems and exposes them to the man command

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		gem shebangfix
USE_RUBY=	yes

NO_ARCH=	yes

SHEBANG_FILES=	rbenv/rbenv_hook_install.sh \
		rbenv/remove_hook_folders.sh

post-patch:
	@${REINPLACE_CMD} -e 's|/share/man|/man|' \
		${WRKSRC}/README.md \
		${WRKSRC}/lib/rubygems/commands/manpages_command.rb \
		${WRKSRC}/lib/rubygems_plugin.rb \
		${WRKSRC}/rbenv/hooks/version-name-change-man.bash \
		${WRKSRC}/rbenv/vars.sh

.include <bsd.port.mk>
