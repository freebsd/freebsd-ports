function split_url(s,	url_scheme, url_fragment, url_query, url_query_parts, i, url_query_part, url_authority, url_auth, url_user, url_host) {
	delete url
	# scheme:[//[user[:password]@]host[:port]][/path][?query][#fragment]
	split(s, url_scheme, "://")
	url["scheme"] = url_scheme[1]

	split(url_scheme[2], url_fragment, "#")
	url["fragment"] = url_fragment[2]

	split(url_fragment[1], url_query, "?")

	split(url_query[2], url_query_parts, "&")
	# url["query"] list of query keys (space separated)
	# url["query", key] value
	for (i = 1; i <= length(url_query_parts); i++) {
		split(url_query_parts[i], url_query_part, "=")
		url["query"] = url["query"] " " url_query_part[1]
		url["query", url_query_part[1]] = url_query_part[2]
	}

	split(url_query[1], url_authority, "/")
	url["path"] = substr(url_query[1], length(url_authority[1]) + 1)

	split(url_authority[1], url_auth, "@")

	if (length(url_auth) == 2) {
		split(url_auth[1], url_user, ":")
		url["user"] = url_user[1]
		url["password"] = url_user[2]
		split(url_auth[2], url_host, ":")
	} else {
		url["user"] = ""
		url["password"] = ""
		split(url_auth[1], url_host, ":")
	}
	url["host"] = url_host[1]
	url["port"] = url_host[2]
}
