{
#  printf("mv %s %s\n", $1, tolower($1));
  printf("tr -d \r < %s | tr -d \032 > %s && rm %s\n", $1, tolower($1), $1);
}
