# $FreeBSD$

PORTNAME=	gitaly
DISTVERSION=	1.20.0
CATEGORIES=	devel

MAINTAINER=	mfechner@FreeBSD.org
COMMENT=	Smart reverse proxy for GitLab

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

# define dependencies that are required for build and run under MY_DEPENDS
MY_DEPENDS=	git>=2.18:devel/git \
		rubygem-bundler>=1.16.5:sysutils/rubygem-bundler \
		rubygem-rugged>=0.27.4:devel/rubygem-rugged \
		rubygem-github-linguist>=6.1:textproc/rubygem-github-linguist \
		rubygem-gitlab-markup>=1.6.5:textproc/rubygem-gitlab-markup \
		rubygem-gitaly-proto>=1.3.0:net/rubygem-gitaly-proto \
		rubygem-activesupport50>=5.0.2:devel/rubygem-activesupport50 \
		rubygem-rdoc>=6.0:devel/rubygem-rdoc \
		rubygem-gitlab-gollum-lib>=4.2:www/rubygem-gitlab-gollum-lib \
		rubygem-gitlab-gollum-rugged_adapter>=0.4.4:www/rubygem-gitlab-gollum-rugged_adapter \
		rubygem-grpc>=1.15.0:net/rubygem-grpc \
		rubygem-sentry-raven>=2.7.2:devel/rubygem-sentry-raven \
		rubygem-faraday>=0.12:www/rubygem-faraday \
		rubygem-rbtrace>0:devel/rubygem-rbtrace \
		rubygem-licensee8>=8.9.0:devel/rubygem-licensee8 \
		rubygem-google-protobuf>=3.6:devel/rubygem-google-protobuf

BUILD_DEPENDS=	go>=1.10:lang/go \
		gem:devel/ruby-gems \
		${MY_DEPENDS}

RUN_DEPENDS=	${MY_DEPENDS} \
		gitlab-shell>=6.0.4:devel/gitlab-shell

USES=		gmake
USE_RUBY=	yes

USE_GITLAB=	yes
GL_ACCOUNT=	gitlab-org
# Find this here: https://gitlab.com/gitlab-org/gitaly/tags
GL_COMMIT=	b9c89add404cc106906f9e9ce5cec58224ae40bc

post-patch:
	${REINPLACE_CMD} -e "s|%%PREFIX%%|${PREFIX}|" ${WRKSRC}/config.toml.example
	${MV} ${WRKSRC}/config.toml.example ${WRKSRC}/config.toml.sample

do-install:
	${MKDIR} ${STAGEDIR}${DATADIR}
	${MKDIR} ${STAGEDIR}${DATADIR}/bin
	${FIND} ${WRKSRC} -name '*.orig' -delete
	${FIND} ${WRKSRC} -name "Gemfile.lock" -delete
	(cd ${WRKSRC}/_build/bin/ && ${COPYTREE_SHARE} .  ${STAGEDIR}${DATADIR}/bin && \
	cd ${WRKSRC} && ${COPYTREE_SHARE} config.toml.sample  ${STAGEDIR}${DATADIR}) && \
	cd ${WRKSRC}/ruby && ${COPYTREE_SHARE} . ${STAGEDIR}${DATADIR}/ruby

.include <bsd.port.mk>
